#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //初始化客户端对象
    socket = new QTcpSocket();
    connect_socket();

    //连接槽信号
    //关联readyRead和socket_Read_Data槽函数。服务器有数据发送时，会自动触发readyRead信号
    QObject::connect(socket,&QTcpSocket::readyRead,this,&MainWindow::socket_Read_Data);
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
    connect(&logon, SIGNAL(logOnSucc()), this, SLOT(hideLogOn()));
    connect(&registerW, SIGNAL(sendInfo(QJsonObject)), this, SLOT(getRegisterInfo(QJsonObject)));
    connect(&logon, SIGNAL(needRegister()), this, SLOT(showRegister()));
    connect(&logon, SIGNAL(sendLogOnInfo(QJsonObject)), this, SLOT(getUserLogon(QJsonObject)));
    connect(&registerW, SIGNAL(ImgSrcSignal(QJsonObject)), this, SLOT(updateImgSrc(QJsonObject)));
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

void MainWindow::updateImgSrc(QJsonObject infoJson) {
    send_socketInfo(infoJson);
}

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

//连接槽函数
void MainWindow::connect_socket()
{
    //取消所有连接
    socket->abort();
    //连接服务器
    socket->connectToHost("127.0.0.1",6666);
    if(!socket->waitForConnected(3000)) {
        qDebug() << "连接服务器请求失败，请重新操作";
    } else {
        qDebug() << "连接服务器成功" << endl;
        QMessageBox::warning(this,"warning",tr("连接服务器成功"),QMessageBox::Yes,QMessageBox::No);
    }
}

void MainWindow::SaveProductInfo(QJsonArray array) {
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
        ProductInfo.push_back(product);
    }
    showRecommend();
}

//读缓冲区槽函数
void MainWindow::socket_Read_Data() {
    QByteArray buffer;
    //读取缓冲区数据
    buffer = socket->readAll();
    //显示缓冲区数据
//    QMessageBox::warning(this, "socket_info", buffer);
    QJsonObject jsonObject = QJsonDocument::fromJson(buffer).object();
    if(jsonObject["type"] == "isLogon") {
        if(jsonObject["warning"].toString() == "Logon Successfully!") {
            // 登录成功后，LogonBtn上需要显示切换用户
            showLogon(jsonObject);
        } else {
            QMessageBox::warning(this, "warning", jsonObject["warning"].toString());
        }
    }
    else if(jsonObject["type"] == "searchProductInfo") {
        if(jsonObject["warning"].toString() == "Successfully!") {
            QJsonArray array = jsonObject["array"].toArray();
            SaveProductInfo(array);
        }
    }
    else if (jsonObject["type"] == "queryResult"){
        ProductInfo.clear();
        if(jsonObject["warning"] == "Successfully!") {
            QJsonArray array = jsonObject["array"].toArray();
            SaveProductInfo(array);
        }
    }
    else if(jsonObject["type"] == "logout") {
        if(jsonObject["isLogOutSucc"] == "true") {
            QMessageBox::information(this, "Info", "Logout successfully");
            ui->userName_label->setText("");
            changeLogOnPic();
        } else {
            QMessageBox::information(this, "Info", "Logout failed");
        }
    }
    else if(jsonObject["type"] == "UserRegister") {
        if(jsonObject["warning"] == "Successfully!") {
            registerW.SaveImg();
            registerW.hide();
        } else {
            QMessageBox::warning(this, "warning", jsonObject["warning"].toString());
        }
    }
    else if(jsonObject["type"] == "updateImgSrc") {
        if(jsonObject["warning"] == "Successfully!") {
            QMessageBox::warning(this,"warning", "Update Img Successfully!");
        } else {
            QMessageBox::warning(this,"warning", "Update Img failed!");
        }
    }
    else if(jsonObject["type"] == "queryComment") {
        QJsonArray array = jsonObject["array"].toArray();
        int labelId = jsonObject["labelId"].toInt();
        MylabelVec[labelId]->commentInfo = array;
        QString str = MylabelVec[labelId]->lineEdit.text() == "true" ? "false" : "true";
        MylabelVec[labelId]->lineEdit.setText(str);
    }
}

void MainWindow::socket_Disconnected() {

}

void MainWindow::changeLogOnPic() {
    ui->LogonBtn->setText(tr("登录"));
    QImage *img = new QImage;
    img->load("E:\\Qt\\Shopping\\Game\\pic\\productPic\\unlog.jpg");
    QImage newImg = img->scaled(ui->picLabel->width(), ui->picLabel->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->picLabel->setPixmap(QPixmap::fromImage(newImg));
}

void MainWindow::initDB() {
    getData();
}

void MainWindow::initBtnGroup() {
    buttonGroup->addButton(ui->category1, 0);
    buttonGroup->addButton(ui->category2, 1);
    buttonGroup->addButton(ui->category3, 2);
    buttonGroup->addButton(ui->category4, 3);
}

// 初始化ComboBox
void MainWindow::init_Combobox() {
    ui->priceBox->addItem("价格从低到高");
    ui->priceBox->addItem("价格从高到低");
    ui->newBox->addItem("从新到旧");
    ui->newBox->addItem("从旧到新");
    ui->chooseBox->addItem("筛选");
}

void MainWindow::setScrollBar() {
    ui->showArea->setBackgroundRole(QPalette::Dark);
    ui->showArea->show();
}

void MainWindow::showRecommend() {
    QGridLayout *layout = new QGridLayout;
    QWidget *containWidget = new QWidget;

    MylabelVec.clear();
    // 加载数据库中的图片信息
    for(int i = 0;i < ProductInfo.size();i++) {
        QString ID = ProductInfo[i].product_id;
        Mylabel *label = new Mylabel("this", this, ID);

        connect(label, SIGNAL(clicked(int,QString)), this, SLOT(createProductShow(int,QString)));
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

void MainWindow::createProductShow(int i, QString productId) {
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

void MainWindow::sendPraise(QJsonObject praiseJson) {
    send_socketInfo(praiseJson);
}

void MainWindow::sendComment(QJsonObject commentJson) {
    if(ui->userName_label->text() == "") {
        QMessageBox::warning(this, "warning", "Please logon first!");
        logon.show();
        return ;
    }
    commentJson["User_name"] = ui->userName_label->text();
    send_socketInfo(commentJson);
}

void MainWindow::getComment(int labelId, QString productId) {
    QJsonObject InfoJson;
    InfoJson["type"] = "queryComment";
    InfoJson["labelId"] = labelId;
    InfoJson["ProductId"] = productId;
    send_socketInfo(InfoJson);
}

// 从数据库获取Product信息
void MainWindow::getData() {
    QJsonObject Infojson;
    Infojson["type"] = "searchProductInfo";
    send_socketInfo(Infojson);
}

// 将获取的产品信息返回给用户
QVector<Product> MainWindow::getProductInfo() {
    return ProductInfo;
}

void MainWindow::PrintProductInfo() {
    for(QVector<Product>::iterator iter = ProductInfo.begin();iter != ProductInfo.end();iter++) {
        qDebug() << iter->product_id << " " << iter->seller_name << " " << QString(iter->state) << " " << QString("%1").arg(iter->price) << " " << iter->description << " " << iter->src << " " << iter->tag << endl;
    }
    qDebug() << endl;
}

MainWindow::~MainWindow()
{
    // 表示进行退出登录操作
    QJsonObject object;
    object["type"] = "logout";
    object["User_name"] = ui->userName_label->text();
    send_socketInfo(object);
    delete ui;
}

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

void MainWindow::showQueryRes(QVector<Product> productRes) {
    ProductInfo = productRes;
    showRecommend();
}

void MainWindow::on_messageBtn_clicked()
{

}

void MainWindow::on_MyBtn_clicked()
{
    mydialog.show();
}

void MainWindow::on_releaseBtn_clicked()
{

}

void MainWindow::on_firstPageBtn_clicked()
{
    getData();
    showRecommend();
}

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

void MainWindow::hideLogOn() {
    logon.hide();
}

void MainWindow::showRegister() {
    registerW.show();
}

void MainWindow::getUserLogon(QJsonObject Infojson) {
    send_socketInfo(Infojson);
}

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

