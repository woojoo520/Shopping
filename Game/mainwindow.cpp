#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
 * @brief initialize the client object and the interface
 * You need to link to the server first. Then you need to get and load the product information from the server and display it on the home page. ANd the most important thing is to complete the connection between signal and slot
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    conn = new QTcpSocket;
    //初始化客户端对象
    socket = new QTcpSocket();
//    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::dataArrived);
    //关联readyRead和socket_Read_Data槽函数。服务器有数据发送时，会自动触发readyRead信号
//    connectToHost("127.0.0.1", 23333);
    connect(socket,&QTcpSocket::readyRead,this,&MainWindow::socket_Read_Data);
    connect(socket, &QTcpSocket::disconnected, this, &MainWindow::connDisconnected);
    in.setDevice(socket);
    in.setVersion(QDataStream::Qt_5_10);
    connect_socket();

    initDB();
    QImage *logo = new QImage;
    logo->load(":/new/BUPT/pic/BUPT3.png");
    ui->pic_label->setPixmap(QPixmap::fromImage(*logo));
    buttonGroup = new QButtonGroup(this);
    changeLogOnPic();
    initBtnGroup();
    init_Combobox();
    setScrollBar();
    showRecommend();
    this->show();
    /// connect the logon's "logonSucc" signal to the slot function "hideLogOn" of the mainWindow, that is once the user is login successfully, the login GUI should be hide
    connect(&logon, SIGNAL(logOnSucc()), this, SLOT(hideLogOn()));
    /// connect the register's "sendInfo" signal to the slot function "getRegisterInfo" of the mainWindow, that is when the user click the register button, the client should get the infoemation of the user, including the user name and password, and send it to the server whether the user login successfully or not
    connect(&registerW, SIGNAL(sendInfo(QJsonObject)), this, SLOT(getRegisterInfo(QJsonObject)));
    /// connect the logon's "needRegister" signal to the slot function "showRegister" of the mainWindow, that is when the user is new to this application, the user should register an account, then the register GUI should to be shown
    connect(&logon, SIGNAL(needRegister()), this, SLOT(showRegister()));
    /// connect the logon's "sendLogOnInfo" signal to the slot function "getUserLogon" of the mainWindow, that is when the user want to login, and click the login button, the client terminal should get the information and send it to server to check out, whether the user's information is correct, and whether the user is login or not
    connect(&logon, SIGNAL(sendLogOnInfo(QJsonObject)), this, SLOT(getUserLogon(QJsonObject)));
    /// connect the registerW's "ImgsrcSignal" signal to the slot function "updateImgSrc" of the mainWindow, that is we should get the src of the picture when user refreash teh interface
    connect(&registerW, SIGNAL(ImgSrcSignal(QJsonObject)), this, SLOT(updateImgSrc(QJsonObject)));
    /// connect the mainWindow's "showRelease" signal to the "showRelease" slot of the release, that is when the user want to release a product, and the release GUI should be shown 
    connect(this, SIGNAL(showRelease()), &release, SLOT(showRelease()));
    /// connect the release's "releasePro" signal to the slot "showRelease" of the mainWindow, that is when the user implement teh information of the product he wants to release, then the client terminal should send the message to the server, update the database and insert the product information to the databse
    connect(&release, SIGNAL(releasePro(QJsonObject)), this, SLOT(releaseProduct(QJsonObject)));
    /// connect the mainWindow's "showMsgSignal" signal to the slot "shoeMsg" of the showmsg, that is when the user want to open the message box, and click the "message" button, the message GUI should be present, and the information of the order massage should the present too, therefore the client terminal should send message to the server to get the order message including the processed massage and unprocessed message
    connect(this, SIGNAL(showMsgSignal()), &showmsg, SLOT(showMsg()));
    /// connect the showmsg's "readXmsg" signal to the slot "getMsgIndex" of the mainWindow, that is when the specific message is read, the client terminal should send a message to the server and update the database of readMsg and UnreadMsg
    connect(&showmsg, SIGNAL(readXmsg(int)), this, SLOT(getMsgIndex(int)));
/*  查看Qt当前的工作路径，这涉及到UserLogo的保存位置
    QString fileName = QCoreApplication::applicationDirPath();
    qDebug() << fileName << endl;
*/

//    QList<QHostAddress> list = QNetworkInterface::allAddresses();
//    foreach (QHostAddress address, list) {
//        if(address.protocol() == QAbstractSocket::IPv4Protocol) {
//            QMessageBox::warning(this, "warning", address.toString());
//        }
//    }
}

/**
 * @brief send the product information to be published to the server 
 * @param productInfo the productInfo's data format is JSON, which including the information of the product, such as product's name, id, price, amount and the description. And the type of the message is "ReleaseProduct", the user name is getting from the mainWindow which pocess of the user infomation
 */
void MainWindow::releaseProduct(QJsonObject productInfo) {
    productInfo["type"] = "releaseProduct";
    productInfo["seller_name"] = ui->userName_label->text();
    productInfo["User_name"] = ui->userName_label->text();
    send_socketInfo(productInfo);
}

/**
 * @brief send the message to server to require the picture src of the product 
 * @param infoJson the inforJson includin the product Id
 */
void MainWindow::updateImgSrc(QJsonObject infoJson) {
    send_socketInfo(infoJson);
}

/**
 * @brief send data to the server
 * @param infoJson the data format of the parameter is JSON, and the type field determining the content of the message to the server, also determining how the server interprets this information
 * if the message is sent successfully, it will show nothing, others, it will show a warning message box
 */
void MainWindow::send_socketInfo(QJsonObject infoJson) {
    qint64 writeResult = socket->write(QJsonDocument(infoJson).toBinaryData());
    bool BoolFlush = socket->flush();
    if(writeResult != -1 && BoolFlush == 1) {
        //返回值不为-1，则发送数据成功
        if(writeResult == 0) {
            QMessageBox::warning(this,"warning",tr("写数据结果的返回值为0"));
        }
    }
}

/**
 * @brief connect to the server
 * the function is to connect to the server which IP address and the port is fixed. If connect failed, it will show you a warning message box, ot, you will see "connected successfully!"
 */
//连接槽函数
void MainWindow::connect_socket()
{
    //取消所有连接
    socket->abort();
    //连接服务器
    socket->connectToHost("127.0.0.1",23333);
    while(!socket->waitForConnected(3000)) {
        QMessageBox::StandardButton r = QMessageBox::question(this, "warning", "连接失败，还要继续连接吗?", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        if(r == QMessageBox::Yes) {
            socket->connectToHost("127.0.0.1",23333);
        } else {
            return ;
        }
    }
    QMessageBox::warning(this,"warning",tr("连接服务器成功"),QMessageBox::Yes,QMessageBox::No);
//    if(!socket->waitForConnected(3000)) {
//        qDebug() << "连接服务器请求失败，请重新操作";
//        QMessageBox::warning(this, "warning", "连接失败");
//    } else {
//        qDebug() << "连接服务器成功" << endl;
//        QMessageBox::warning(this,"warning",tr("连接服务器成功"),QMessageBox::Yes,QMessageBox::No);
//    }
}

/**
 * @brief save the information of the product info which is to be shown on the home page
 * @param array
 * @param type  if the type is user, it means that the information should be save in the mainWindow to be shown in the home page, or it means that the information of the product is the product you relase, it should be saved in the releaseProduct vector
 * To sum up, the function save the product information whether it should be shown in the home page or shown in the release GUI to show the product the user release 
 */
void MainWindow::SaveProductInfo(QJsonArray array, QString type) {
    ProductInfo.clear();
    release.releaseProduct.clear();
    for(int i = 0;i < array.size();i++) {
        QJsonObject productJson = array.at(i).toObject();
        Product product;
        product.product_id  = productJson["product_id"].toString();
        product.seller_name = productJson["seller_name"].toString();
        product.state       = productJson["state"].toString().toInt();
        product.price       = productJson["price"].toString().toFloat();
        product.description = productJson["description"].toString();
        product.src         = productJson["src"].toString();
        product.tag         = productJson["tag"].toString();
        if(type == "user") {
            ProductInfo.push_back(product);
        } else {
            release.releaseProduct.push_back(product);
        }
    }
    if(type == "user") {
        showRecommend();
    } else {
        emit showRelease();
    }

}

/**
 * @brief read data in the buffer
 * 
 * we should infer the message type and find the correct way to interpret teh message
 */
//读缓冲区槽函数
void MainWindow::socket_Read_Data() {
    QByteArray buffer;
    //读取缓冲区数据
    buffer = socket->readAll();
    //显示缓冲区数据
    QJsonObject jsonObject = QJsonDocument::fromJson(buffer).object();
    ui->textEdit->setText(QString(QJsonDocument(jsonObject).toJson()));
//    QMessageBox::warning(this, "warning", QString(QJsonDocument(jsonObject).toJson()));

    /// if the type is "isLogon", it shows that whether the user login successfully or not, if the user login successfully, the message will include the logo of the user, the meassge(including the read message and the unread message) of the user,  and other information about the user, what the client terminal should do is load the logo of the user, and the button shouldn't be login anymore, but the logout. if the user's login is not successful, then the user should reinput the user name and password adn send the login message again to the server
    if(jsonObject["type"] == "isLogon") {
        if(jsonObject["warning"].toString() == "Logon Successfully!") {
            // 登录成功后，LogonBtn上需要显示切换用户
            showLogon(jsonObject);
            if(jsonObject["unreadMsg"].toArray().size() > 0) {
                QImage *img = new QImage;
                img->load("E:\\Qt\\Shopping\\Game\\pic\\otherpic\\msg.png");
                QImage newImg = img->scaled(ui->msg_label->width(), ui->msg_label->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                ui->msg_label->setPixmap(QPixmap::fromImage(newImg));
                ui->msg_label->show();
                ui->msg_label->raise();
                showmsg.unreadMsg = jsonObject["unreadMsg"].toArray();
            }
            showmsg.readMsg = jsonObject["readMsg"].toArray();
        } else {
            if(jsonObject["User_name"].toString().toInt() == 0) {
                forcedToLogout();
            }
        }
    }
    /// if the type is "searchProductInfo", it shows that the information is 
    else if(jsonObject["type"] == "searchProductInfo") {
        if(jsonObject["warning"].toString() == "Successfully!") {
            QJsonArray array = jsonObject["array"].toArray();
            SaveProductInfo(array, jsonObject["object"].toString());
        }
    }
    /// if the type is "querResult", it show that the it shows that the information is about the product, including the product name, id, price, description and so on. And the mainWindow show load these information in the GUI
    else if (jsonObject["type"] == "queryResult"){
        ProductInfo.clear();
        if(jsonObject["warning"] == "Successfully!") {
            QJsonArray array = jsonObject["array"].toArray();
            SaveProductInfo(array, "user");
        }
    }
    /// if the type is "logout", it shows that the user wants to logout, and delete the user infomation in the client terminal
    else if(jsonObject["type"] == "logout") {
        if(jsonObject["isLogOutSucc"] == "true") {
            QMessageBox::information(this, "Info", "Logout successfully");
            ui->userName_label->setText("");
            changeLogOnPic();
        } else {
            QMessageBox::information(this, "Info", "Logout failed");
        }
    }
    /// if the type is "UserRegister", it shows that the message is about whether the user register successfully or not. If the user failed in register, it will pop up a warning message box, or you will see "logout successfully!" 
    else if(jsonObject["type"] == "UserRegister") {
        if(jsonObject["warning"] == "Successfully!") {
            registerW.SaveImg();
            registerW.hide();
        } else {
            QMessageBox::warning(this, "warning", jsonObject["warning"].toString());
        }
    }
    /// if the type is "updateImgSrc", it shows that the message is about whether the image is updated!
    else if(jsonObject["type"] == "updateImgSrc") {
        if(jsonObject["warning"] == "Successfully!") {
            QMessageBox::warning(this,"warning", "Update Img Successfully!");
        } else {
            QMessageBox::warning(this,"warning", "Update Img failed!");
        }
    }
    /// if the type is "queryComment", it shows that the information is about the comment of the specific product.
    else if(jsonObject["type"] == "queryComment") {
        QJsonArray array = jsonObject["array"].toArray();
        int labelId = jsonObject["labelId"].toInt();
        MylabelVec[labelId]->commentInfo = array;
        QString str = MylabelVec[labelId]->lineEdit.text() == "true" ? "false" : "true";
        MylabelVec[labelId]->lineEdit.setText(str);
    } 
    /// if the type is "releaseProduct", it shows that the message about whether the product release successfully or not
    else if(jsonObject["type"] == "releaseProduct") {
        if(jsonObject["warning"].toString() == "Successfully!") {
            SaveProductInfo(jsonObject["array"].toArray(), "seller");
        }
    } 
    /// if the type is "sendMsg", it shows that the message is about that you have received a new order message, and you nedd to deal with it.
    else if(jsonObject["type"] == "sendMsg") {
        QMessageBox::warning(this, "warning", jsonObject["Msg"].toString());
        ui->userName_label->show();
    }
    /// if the type is "getMsg", it shows that the message is about the read message and the unread message.
    else if(jsonObject["type"] == "getMsg") {
        showmsg.unreadMsg = jsonObject["unreadMsg"].toArray();
        showmsg.readMsg = jsonObject["readMsg"].toArray();
        emit showMsgSignal();
        showmsg.show();
    }
    else if(jsonObject["type"] == "productShowMsg") {
        createProductShow(jsonObject);
    }
}

/**
 * @brief change the logo picture of the user if the user login successfully
 */
void MainWindow::changeLogOnPic() {
    ui->LogonBtn->setText(tr("登录"));
    QImage *img = new QImage;
    img->load("E:\\Qt\\Shopping\\Game\\pic\\productPic\\unlog.jpg");
    QImage newImg = img->scaled(ui->picLabel->width(), ui->picLabel->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->picLabel->setPixmap(QPixmap::fromImage(newImg));
}

/**
 * @brief get the product information to be shown in the home page
 */
void MainWindow::initDB() {
    getData();
}

/**
 * @brief add the category button in the home page to select the product the user want
 */
void MainWindow::initBtnGroup() {
    buttonGroup->addButton(ui->category1, 0);
    buttonGroup->addButton(ui->category2, 1);
    buttonGroup->addButton(ui->category3, 2);
    buttonGroup->addButton(ui->category4, 3);
}
/**
 * @brief initialize the combobox to add some options about user selection, such as price, new and old, and other filter conditions
 */
// 初始化ComboBox
void MainWindow::init_Combobox() {
    ui->priceBox->addItem("价格从低到高");
    ui->priceBox->addItem("价格从高到低");
    ui->newBox->addItem("从新到旧");
    ui->newBox->addItem("从旧到新");
    ui->chooseBox->addItem("筛选");
}

/**
 * initialize the scrollbar
 */
void MainWindow::setScrollBar() {
    ui->showArea->setBackgroundRole(QPalette::Dark);
    ui->showArea->show();
}

void MainWindow::productShowMsg(int i, QString productId) {
    QJsonObject showMsg;
    showMsg["type"] = "productShowMsg";
    showMsg["labelId"] = i;
    showMsg["productId"] = productId;
    send_socketInfo(showMsg);
}

/**
 * @brief initialize the product information of the home page
 * Display the product information in the middle of the interface and display it in the specific layout. It will show the product picture, description, and the price. If you click the product picture, you will see detail information about the product 
 */
void MainWindow::showRecommend() {
    QGridLayout *layout = new QGridLayout;
    QWidget *containWidget = new QWidget;

    MylabelVec.clear();
    // 加载数据库中的图片信息
    for(int i = 0;i < ProductInfo.size();i++) {
        QString ID = ProductInfo[i].product_id;
        Mylabel *label = new Mylabel("this", this, ID);

//        connect(label, SIGNAL(clicked(int,QString)), this, SLOT(createProductShow(int,QString)));
        connect(label, SIGNAL(clicked(int,QString)), this, SLOT(productShowMsg(int,QString)));
        label->resize(200, 200);
        QImage *img = new QImage;
        bool isLoadSucc = img->load(ProductInfo[i].src);
        if(!isLoadSucc) {
            img->load("E:\\Qt\\Shopping\\Game\\pic\\productPic\\unload.jpg");
        }
        QImage newImg = img->scaled(label->width(), label->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        label->setPixmap(QPixmap::fromImage(newImg));
        label->tag = i;

        QLabel *textLabel = new QLabel(this);
        textLabel->setText(ProductInfo[i].description);
        textLabel->setWordWrap(true);
        QLabel *priceLabel = new QLabel(this);
        priceLabel->setText("￥" + QString("%1").arg(ProductInfo[i].price));
        layout->addWidget(label, 2 * i, 0, 2, 1);
        layout->addWidget(textLabel, 2 * i, 1, 1, 1);
        layout->addWidget(priceLabel, 2 * i + 1, 1, 1, 1);
        MylabelVec.push_back(label);
    }

    containWidget->setLayout(layout);
    ui->showArea->setWidgetResizable(true);
    ui->showArea->setWidget(containWidget);

}

/**
 * @brief create an interface to show the product
 * @param i the label index of the product 
 * @param productId the id of the product 
 * when the user click the product picture to show his interests in this product, the user will see a dialog about the detailed information, which incluing the description od the product, the comment button to show the comment of the product, and the button tho add the product into the user's cart, and a chat button to chat with the seller  
 */
void MainWindow::createProductShow(QJsonObject info) {
    int i = info["labelId"].toString().toInt();
    QString productId = info["productId"].toString();
    QString product_name = info["product_name"].toString();





    productShow *productshow = new productShow(this, i, productId);
    productshow->show();
    comment *c = new comment(this, i, productId);
    connect(productshow, SIGNAL(getComment(int, QString)), this, SLOT(getComment(int, QString)));
    connect(c, SIGNAL(sendComment(QJsonObject)), this, SLOT(sendComment(QJsonObject)));
    connect(productshow->pushButton, SIGNAL(clicked(bool)), c, SLOT(Show()));
    connect(c, SIGNAL(queryComment(int,QString)), this, SLOT(getComment(int,QString)));
    connect(MylabelVec[i], SIGNAL(showC(QJsonArray)), c, SLOT(showComment(QJsonArray)));

    connect(c, SIGNAL(sendPraise(QJsonObject)), this, SLOT(sendPraise(QJsonObject)));
}

/**
 * @brief send the message to the server that the user "thumb-up" to one of the comment
 */
void MainWindow::sendPraise(QJsonObject praiseJson) {
    send_socketInfo(praiseJson);
}

/**
 * @brief send the comment of the product to server
 * when the user is not login, he or she will be forced to login before comment. If the user is login successfully, he or she can comment the product 
 */
void MainWindow::sendComment(QJsonObject commentJson) {
    if(ui->userName_label->text() == "") {
        QMessageBox::warning(this, "warning", "Please logon first!");
        logon.show();
        return ;
    }
    commentJson["User_name"] = ui->userName_label->text();
    send_socketInfo(commentJson);
}

/**
 * @brief send the message to told the server that the user has dealed with the order 
 * @param id the id of the unread message
 */
void MainWindow::getMsgIndex(int id) {
    QJsonObject msgJson;
    msgJson["Id"] = id;
    msgJson["type"] = "readXMsg";
    send_socketInfo(msgJson);
}

/**
 * @brief get the comment of the product
 * @param labelId the id of the product label 
 * @param productId the id of the product 
 * these parameters may seems to be useless, but it is usefull when the client terminal get the response of the server to show the spcific comment od the product.
 */
void MainWindow::getComment(int labelId, QString productId) {
    QJsonObject InfoJson;
    InfoJson["type"] = "queryComment";
    InfoJson["labelId"] = labelId;
    InfoJson["ProductId"] = productId;
    send_socketInfo(InfoJson);
}

/**
 * @param get the information of teh product from the database
 */
// 从数据库获取Product信息
void MainWindow::getData() {
    QJsonObject Infojson;
    Infojson["type"] = "searchProductInfo";
    Infojson["object"] = "user";
    send_socketInfo(Infojson);
}

/**
 * @brief return the information to user about the product information
 */
// 将获取的产品信息返回给用户
QVector<Product> MainWindow::getProductInfo() {
    return ProductInfo;
}

/**
 * @brief debug, show the product information which is sent from the server
 */
void MainWindow::PrintProductInfo() {
    for(QVector<Product>::iterator iter = ProductInfo.begin();iter != ProductInfo.end();iter++) {
        qDebug() << iter->product_id << " " << iter->seller_name << " " << QString(iter->state) << " " << QString("%1").arg(iter->price) << " " << iter->description << " " << iter->src << " " << iter->tag << endl;
    }
    qDebug() << endl;
}

/**
 * @brief deconstruction of the mainWindow
 * if the user iis still login, then it will send a message to logout the user
 */
MainWindow::~MainWindow()
{
    // 表示进行退出登录操作
    QJsonObject object;
    object["type"] = "logout";
    object["User_name"] = ui->userName_label->text();
    send_socketInfo(object);
    delete ui;
}

/**
 * @brief get the information if the product that the user want after adding some restriction and send the request to server
 */
void MainWindow::on_searchBtn_clicked()
{
    QString searchP = ui->searchEdit->text();
    QString priceQuery = (ui->priceBox->currentIndex() == 0 ? tr("from low to high") : tr("from high to low"));
    QString newQuery = (ui->newBox->currentIndex() == 0 ? tr("from new to old") : tr("from old to new"));
    QString catogary = "";
    int select = buttonGroup->checkedId();
    switch (select) {
    case 0:
        catogary = tr("food");
        break;
    case 1:
        catogary = tr("BBQ");
        break;
    case 2:
        catogary = tr("bread");
        break;
    case 3:
        catogary = tr("相机");
        break;
    default:
        break;
    }
    QJsonObject query;
    query["type"] = "queryResult";
    query["searchP"] = searchP; // search Product Info
    query["priceQuery"] = priceQuery;
    query["newQuery"] = newQuery;
    query["catogary"] = catogary;
    send_socketInfo(query);
}

/**
 * @brief basing on the product vector, show the information about the product in the recomment module
 */
void MainWindow::showQueryRes(QVector<Product> productRes) {
    ProductInfo = productRes;
    showRecommend();
}

/**
 * @brief send the request of getting the message to server
 */ 
void MainWindow::on_messageBtn_clicked()
{
    // 上面这部分是虚构的，即这部分内容应该写在点击下订单按钮之后，然后将订单消息发送出去，不应该在这部分中处理
//    QJsonObject query;
//    query["type"] = "order";
//    query["user_name"] = ui->userName_label->text();
//    query["SellerName"] = "ZJY";
//    query["Msg"] = "Hello, I am ZJY";
//    send_socketInfo(query);

   ui->msg_label->hide();
   QJsonObject getMsgObj;
   getMsgObj["type"] = "getMsg";
   getMsgObj["User_name"] = ui->userName_label->text();
   send_socketInfo(getMsgObj);
}

void MainWindow::on_MyBtn_clicked()
{
    mydialog.show();
}

/**
 * @brief show the release interface
 * if the user is not login, then the user should be forced to login, and release the product after.
 */
void MainWindow::on_releaseBtn_clicked()
{
    if(ui->userName_label->text() == "") {
        QMessageBox::warning(this, "warning", "Please logon first!");
        logon.show();
        return ;
    }
    QJsonObject releaseInfo;
    releaseInfo["type"] = "searchProductInfo";
    releaseInfo["object"] = "seller";
    releaseInfo["User_name"] = ui->userName_label->text();
    send_socketInfo(releaseInfo);
    release.show();
}

/**
 * @brief after you click the home page button, it will be reset
 */
void MainWindow::on_firstPageBtn_clicked()
{
    getData();
    showRecommend();
}

/**
 * @brief show the login interface and change the button's text to "logout" or "login" 
 */
void MainWindow::on_LogonBtn_clicked()
{
    if(ui->LogonBtn->text() == tr("登录")) {
        logon.show();
    } else {
        // 表示进行退出登录操作
        QJsonObject object;
        object["type"] = "logout";
        object["User_name"] = ui->userName_label->text();
        send_socketInfo(object);
    }
}

/**
 * hide the login interface
 */
void MainWindow::hideLogOn() {
    logon.hide();
}

/**
 * show the register interface
 */
void MainWindow::showRegister() {
    registerW.show();
}

/**
 * @brief send the register information to server 
 */
void MainWindow::getUserLogon(QJsonObject Infojson) {
    send_socketInfo(Infojson);
}

/**
 * @brief change the logo
 */
void MainWindow::showLogon(QJsonObject jsonObject) {
    logon.hide();
    ui->LogonBtn->setText(tr("退出登录"));
    ui->picLabel->setGeometry(700, 20, 60, 60);
    QImage *img = new QImage;
    img->load(jsonObject["usr_logo"].toString());
    QImage newImg = img->scaled(ui->picLabel->width(), ui->picLabel->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->picLabel->setPixmap(QPixmap::fromImage(newImg));
    ui->userName_label->setText(jsonObject["usr_name"].toString());
    ui->picLabel->show();
}

void MainWindow::getRegisterInfo(QJsonObject infoJson) {
    send_socketInfo(infoJson);
}

void MainWindow::connectToHost(const QString &hostName, quint16 port) {
    socket->connectToHost(hostName, port);
}

void MainWindow::connDisconnected() {
    dataQ.clear();
//    ui->textEdit->setText("链接丢失");
    QMessageBox::warning(this, "warning", "Disconnect");
    connect_socket();
}

void MainWindow::forcedToLogout() {
    QMessageBox::warning(this, "warning", "您的账号已经在其他地方登陆，您被强制下线");
    ui->userName_label->setText("");
    changeLogOnPic();
}
