#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initDB();
    QImage *logo = new QImage;
    logo->load(":/new/BUPT/pic/BUPT3.png");
    ui->pic_label->setPixmap(QPixmap::fromImage(*logo));

    init_Combobox();
    setScrollBar();
    showRecommend();
    this->show();
    connect(&logon, SIGNAL(logOnSucc()), this, SLOT(hideLogOn()));
    connect(&registerW, SIGNAL(sendInfo(QVector<QString>)), this, SLOT(getRegisterInfo(QVector<QString>)));
    connect(&logon, SIGNAL(needRegister()), this, SLOT(showRegister()));
    connect(&logon, SIGNAL(sendLogOnInfo(QVector<QString>)), this, SLOT(getUserLogon(QVector<QString>)));
    connect(&db, SIGNAL(sendImg()), &registerW, SLOT(SaveImg()));
    connect(&registerW, SIGNAL(ImgSrcSignal(QVector<QString>)), &db, SLOT(updateImgSrc(QVector<QString>)));

/*  查看Qt当前的工作路径，这涉及到UserLogo的保存位置
    QString fileName = QCoreApplication::applicationDirPath();
    qDebug() << fileName << endl;

*/
}

void MainWindow::initDB() {
    if(!db.OpenDatabase()) {
        QMessageBox::warning(this, "Warning", "Sorry, Can't access SQL Server");
    }
    getData();
//    PrintProductInfo();
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

    // 加载数据库中的图片信息
    for(int i = 0;i < ProductInfo.size();i++) {
        Mylabel *label = new Mylabel("this");
        label->resize(200, 200);
        QImage *img = new QImage;
        img->load(ProductInfo[i].src);
        QImage newImg = img->scaled(label->width(), label->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        label->setPixmap(QPixmap::fromImage(newImg));
//        connect(label, SIGNAL(clicked()), label, SLOT(showDetail()));

        QLabel *textLabel = new QLabel(this);
        textLabel->setText(ProductInfo[i].description);
        textLabel->setWordWrap(true);
        QLabel *priceLabel = new QLabel(this);
        priceLabel->setText("￥" + QString("%1").arg(ProductInfo[i].price));
        layout->addWidget(label, 2 * i, 0, 2, 1);
        layout->addWidget(textLabel, 2 * i, 1, 1, 1);
        layout->addWidget(priceLabel, 2 * i + 1, 1, 1, 1);
    }

    containWidget->setLayout(layout);
    ui->showArea->setWidgetResizable(true);
    ui->showArea->setWidget(containWidget);
//    this->setCentralWidget(ui->showArea);

}

// 从数据库获取Product信息
void MainWindow::getData() {
    ProductInfo = db.searchProductInfo();
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
    delete ui;
}

void MainWindow::on_searchBtn_clicked()
{

}

void MainWindow::on_messageBtn_clicked()
{

}

void MainWindow::on_MyBtn_clicked()
{

}

void MainWindow::on_releaseBtn_clicked()
{

}

void MainWindow::on_firstPageBtn_clicked()
{

}

void MainWindow::on_LogonBtn_clicked()
{
    if(ui->LogonBtn->text() == tr("登录")) {
        logon.show();
    } else {
        // 表示进行切换用户操作

    }
}

void MainWindow::hideLogOn() {
    logon.hide();
}

void MainWindow::showRegister() {
    registerW.show();
}

void MainWindow::getUserLogon(QVector<QString> InfoVec) {
    QVector<QString> resInfo = db.isLogon(InfoVec);
    QMessageBox::information(this, "Info", resInfo[0]);
    if(resInfo[0] == "Logon Successfully!") {
        // 登录成功后，LogonBtn上需要显示切换用户
        ui->LogonBtn->setText(tr("切换用户"));

        QLabel *picLabel = new QLabel(this);
        picLabel->setGeometry(700, 20, 60, 60);
        QImage *img = new QImage;
        img->load(resInfo[2]);
        QImage newImg = img->scaled(picLabel->width(), picLabel->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        picLabel->setPixmap(QPixmap::fromImage(newImg));
        ui->userName_label->setText(resInfo[1]);
        picLabel->show();
    }
}

void MainWindow::getRegisterInfo(QVector<QString> InfoVec) {
    QString str = db.UserRegister(InfoVec);
    QMessageBox::information(this, "Info", str);
    if(str == "Register successfully") {
        registerW.hide();

    }
}

void MainWindow::registerUser() {

}
