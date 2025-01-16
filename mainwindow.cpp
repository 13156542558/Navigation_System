#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <bits/stdc++.h>
#include <QMouseEvent>
//#include <QDebug>
#include <QColor>
#include "Graph.h"
#include "mythread.h"
MyThread mythread;//线程
const int pointNum=10000;//点数
bool visShortDistPath[50005];//最短路占用边标记
bool visNearPath[50005];//最近点占用边标记
bool visShortDistPoint[10005];//最短路占用点标记
bool visNearPoint[10005];//最近点占用点标记

QGraphicsLineItem *litem[50005];//边图元
QGraphicsEllipseItem *ellipseitem[50005];//点图元
Graph Gp(pointNum);//构造图
MyGraphicsView *graphicsView;//视图指针
std::vector<int> shortestPath;//最短路存储
std::vector<int> nearPoint;//最近点存储
std::vector<int> nearRespoint;//最近餐馆点存储
std::vector<int> nearGaspoint;//最近加油站点存储

//主窗口构造函数
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);//ui绑定
    m_scene=new QGraphicsScene;//场景创建
    graphicsView=new MyGraphicsView(this);//视图创建绑定主窗口
    graphicsView->resize(680,680);//视图大小设定
    graphicsView->setScene(m_scene);//场景塞进视图
    graphicsView->setSceneRect(0,0,680,680);//场景大小设定
    srand(time(0));
    Gp.startRandFlow();//随机边流量线程启动
    auto edgeNum=Gp.getEdgeNums();//获取边数
    //初始化边图元并塞入场景
    for(int i=0;i<(int)edgeNum;i++)
    {
        litem[i]=new QGraphicsLineItem;
        QGraphicsLineItem *item=litem[i];
        item->setPos(0,0);
        //除50适应实际大小
        item->setLine(Gp.P[Gp.E[i].P1].x/50,Gp.P[Gp.E[i].P1].y/50,Gp.P[Gp.E[i].P2].x/50,Gp.P[Gp.E[i].P2].y/50);
        m_scene->addItem(item);//加入边图元
    }
    //刷新边流量
    updatePath();
    //初始化点塞入场景
    for(int i=1;i<=pointNum;i++)
    {
        ellipseitem[i]=new QGraphicsEllipseItem;
        QGraphicsEllipseItem *item=ellipseitem[i];
        item->setPos(0,0);
        item->setPen(QPen(Qt::black));
        item->setBrush(Qt::black);
        item->setRect(QRect(Gp.P[i].x/50,Gp.P[i].y/50,1,1));
        m_scene->addItem(item);
    }
    //不同流量比例提示颜色
    // ui->toolButton_2->setStyleSheet("background-color: rgb(60,179,113)");
    // ui->toolButton_3->setStyleSheet("background-color: rgb(255,255,0)");
    // ui->toolButton_4->setStyleSheet("background-color: rgb(165,42,42)");
    // ui->toolButton_5->setStyleSheet("background-color: rgb(139,0,0)");
    // ui->toolButton->setStyleSheet("background-color: rgb(128,0,0)");
    // ui->toolButton_2->setStyleSheet("background-color: rgb(60,179,113)");
    // ui->toolButton_3->setStyleSheet("background-color: rgb(255,255,0)");
    // ui->toolButton_4->setStyleSheet("background-color: rgb(165,42,42)");
    // ui->toolButton_5->setStyleSheet("background-color: rgb(139,0,0)");
    // ui->toolButton->setStyleSheet("background-color: rgb(128,0,0)");
    //定时刷新边显示线程启动
    mythread.start();
}
//获取最近100个点
void MainWindow::setNearPoint(double x,double y)
{
    //将之前存储的置零
    for(int i=1;i<(int)nearPoint.size();i++)
    {
        for(auto [_,eg]:Gp.G[nearPoint[i]])
        {
            int num=eg,num2=eg^1;
            visNearPath[num]=visNearPath[num2]=0;
        }
        visNearPoint[nearPoint[i]]=0;
    }
    //刷新一下刷掉之前的
    updatePath();
    updatePoint();
    Point tmp;
    tmp.x=x,tmp.y=y;
    //调用最近点函数
    nearPoint=(Gp.getClosestPoints(tmp));
    //染色
    for(int i=1;i<(int)nearPoint.size();i++)
    {
        for(auto [_,eg]:Gp.G[nearPoint[i]])
        {
            int num=eg,num2=eg^1;//
            visNearPath[num]=visNearPath[num2]=1;
            litem[num]->setPen(QPen(QColor("#4169e1"),2));
            litem[num2]->setPen(QPen(QColor("#4169e1"),2));
        }
        visNearPoint[nearPoint[i]]=1;
        QGraphicsEllipseItem *item=ellipseitem[nearPoint[i]];
        item->setPen(QPen(Qt::blue));
        item->setBrush(Qt::blue);
    }
    //获取点编号和坐标并展示在列表里
    QStringList infStrList;
    QStandardItemModel *ItemModel =new QStandardItemModel(this);
    for(int i=1;i<(int)nearPoint.size();i++)
    {
        QString string="编号："+QString::number(nearPoint[i])+" 坐标：("+QString::number(Gp.P[nearPoint[i]].x)+","+QString::number(Gp.P[nearPoint[i]].y)+")";
        QStandardItem *item=new QStandardItem(string);
        ItemModel->appendRow(item);
    }
    ui->listView->setModel(ItemModel);
    return;
}
//最短路函数
void MainWindow::setShortestPath(int x,int y,int time)
{
    //将之前最短路置零
    for(int i=0;i<(int)shortestPath.size();i++)
    {
        int &num=shortestPath[i];
        int num2=num^1;
        int p1num=Gp.E[num].P1,p2num=Gp.E[num].P2;
        visShortDistPath[num]=visShortDistPath[num2]=0;
        visShortDistPoint[p1num]=visShortDistPoint[p2num]=0;
    }
    //刷掉
    updatePath();
    updatePoint();
    double totalDistance,totalTime;//记录距离和时间
    shortestPath=Gp.dij(x,y,&Gp,time,totalDistance,totalTime);//调用最短路函数
    //最短路染色并展示
    QStringList infStrList;
    QStandardItemModel *ItemModel =new QStandardItemModel(this);


    for(int i=(int)shortestPath.size()-1;i>=0;i--)
    {
        int &num=shortestPath[i];
        int num2=num^1;
        int p1num=Gp.E[num].P1,p2num=Gp.E[num].P2;
        visShortDistPath[num]=visShortDistPath[num2]=1;
        visShortDistPoint[p1num]=visShortDistPoint[p2num]=1;
        litem[num]->setPen(QPen(QColor("#000000"),2));
        litem[num2]->setPen(QPen(QColor("#000000"),2));
        ellipseitem[p1num]->setPen(QPen(Qt::blue,2));
        ellipseitem[p1num]->setBrush(Qt::blue);
        ellipseitem[p2num]->setBrush(Qt::blue);
        ellipseitem[p2num]->setPen(QPen(Qt::blue,2));

        QString string="编号："+QString::number(Gp.E[num].P1)+" 坐标：("+QString::number(Gp.P[Gp.E[num].P1].x)+","+QString::number(Gp.P[Gp.E[num].P1].y)+")";
        QStandardItem *item=new QStandardItem(string);
        ItemModel->appendRow(item);
    }
    QString string="编号："+QString::number(y)+" 坐标：("+QString::number(Gp.P[y].x)+","+QString::number(Gp.P[y].y)+")";
    QStandardItem *item=new QStandardItem(string);
    ItemModel->appendRow(item);
    ui->listView_2->setModel(ItemModel);

    //展示时间和距离
    QString tme="时间：";
    tme+=QString::number(totalTime,'f',2);
    tme+="s";
    ui->toolButton_7->setText(tme);
    QString dis="距离：";
    dis+=QString::number(totalDistance,'f',2);
    dis+="m";
    ui->toolButton_6->setText(dis);

    // //展示初始地点附近的餐馆加油站
    // //调用最近点函数
    Point tmp;
    tmp.x = Gp.P[x].x,tmp.y = Gp.P[x].y;
    nearRespoint=(Gp.GetClosestServicePoints(tmp,Gp.Res));
    nearGaspoint=(Gp.GetClosestServicePoints(tmp,Gp.Gas));
    for(int i=0;i < (int)nearRespoint.size();i++)
    {
        QGraphicsEllipseItem *item_res=ellipseitem[nearRespoint[i]];
        item_res->setPen(QPen(Qt::red));
        item_res->setBrush(Qt::red);

        QGraphicsEllipseItem *item_gas=ellipseitem[nearGaspoint[i]];
        item_gas->setPen(QPen(Qt::yellow));
        item_gas->setBrush(Qt::yellow);
    }

    ui->nearest_gas->setText(" 坐标：("+QString::number(Gp.P[nearGaspoint.back()].x)+","+QString::number(Gp.P[nearGaspoint.back()].y)+")");
    ui->nearest_res->setText(" 坐标：("+QString::number(Gp.P[nearRespoint.back()].x)+","+QString::number(Gp.P[nearRespoint.back()].y)+")");
}
//刷新边
void MainWindow::updatePath()
{
    auto edgeNum=Gp.getEdgeNums();
    //对所有边遍历
    for(int i=0;i<(int)edgeNum;i++)
    {
        QGraphicsLineItem *item=litem[i];
        if(visShortDistPath[i])
        {
            item->setPen(QPen(QColor("#000000"),2));
            continue;
        }
        else if(visNearPath[i])
        {
            item->setPen(QPen(QColor("#4169e1"),2));
            continue;
        }
        //根据流量比例染色
        double fdc=1.0*Gp.E[i].flow/Gp.E[i].capacity;
        if(fdc<=0.5)item->setPen(QColor("#007f00"));
        else if(fdc<=0.8)item->setPen(QColor("#00ff00"));
        else if(fdc<=1.0)item->setPen(QColor("#ffff00"));
        else if(fdc<=1.5)item->setPen(QColor("#ff0000"));
        else item->setPen(QColor("#aa0000"));
    }
}
//刷新点
void MainWindow::updatePoint()
{
    //根据标记染色
    for(int i=1;i<=(int)pointNum;i++)
    {
        if(visShortDistPoint[i]||visNearPoint[i])continue;
        QGraphicsEllipseItem *item=ellipseitem[i];
        item->setPen(QPen(Qt::black));
        item->setBrush(Qt::black);
    }
}
//析构ui界面
MainWindow::~MainWindow()
{
    delete ui;
}

//最近100个点按钮
void MainWindow::on_nearpt_clicked()
{
    double x=ui->inputx->text().toDouble();
    double y=ui->inputy->text().toDouble();
    if(x<0||x>32767||y<0||y>32767)return;//
    MainWindow::setNearPoint(x,y);
}
void MainWindow::on_cancel_clicked()
{
    //将之前存储的置零
    for(int i=0;i<50005;i++)
    {
        visShortDistPath[i]=0;
        visNearPath[i]=0;
    }
    for(int i =0;i<10005;i++)
    {
        visShortDistPoint[i]=0;
        visNearPoint[i]=0;
    }
    //刷新一下刷掉之前的
    updatePath();
    updatePoint();

    ui->inputx_2->setText("");
    ui->inputy_2->setText("");
    ui->coordinate_1->setText("");
    ui->coordinate_2->setText("");
    ui->toolButton_7->setText("时间：");
    ui->toolButton_6->setText("距离：");
    ui->inputx->setText("");
    ui->inputy->setText("");
    ui->nearest_gas->setText("");
    ui->nearest_res->setText("");
    QStandardItemModel *ItemModel =new QStandardItemModel(this);
    ui->listView_2->setModel(ItemModel);
    ui->listView->setModel(ItemModel);
}
//最短路按钮
void MainWindow::on_shortpt_clicked()
{
    int x=ui->inputx_2->text().toInt();
    int y=ui->inputy_2->text().toInt();
    if(x>10000||x<1||y>10000||y<1)return;//
    QString coor1 = "("+QString::number(Gp.P[x].x)+","+QString::number(Gp.P[x].y)+")";
    QString coor2 = "("+QString::number(Gp.P[y].x)+","+QString::number(Gp.P[y].y)+")";
    ui->coordinate_1->setText(coor1);
    ui->coordinate_2->setText(coor2);
    MainWindow::setShortestPath(x,y,0);
}
//时间最短路按钮
void MainWindow::on_pushButton_clicked()
{
    int x=ui->inputx_2->text().toInt();
    int y=ui->inputy_2->text().toInt();
    if(x>10000||x<1||y>10000||y<1)return;//
    QString coor1 = "("+QString::number(Gp.P[x].x)+","+QString::number(Gp.P[x].y)+")";
    QString coor2 = "("+QString::number(Gp.P[y].x)+","+QString::number(Gp.P[y].y)+")";
    ui->coordinate_1->setText(coor1);
    ui->coordinate_2->setText(coor2);
    MainWindow::setShortestPath(x,y,1);
}
//右键双击函数
void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button()!=Qt::RightButton)return;
    QPointF nowAnchor=graphicsView->mapToScene(event->pos());//获取的是视图的坐标要下沉到场景去获取真实坐标
    double x=nowAnchor.x()*50,y=nowAnchor.y()*50;
    if(x<0||x>32767||y<0||y>32767)return;//边界判断
    else
    {
        ui->inputx->setText(QString::number(x));
        ui->inputy->setText(QString::number(y));

        setNearPoint(x,y);
    }
}
//刷新边函数同上（由于线程隔开类的调用）
void MyThread::wode()
{
    auto edgeNum=Gp.getEdgeNums();
    for(int i=0;i<(int)edgeNum;i++)
    {
        QGraphicsLineItem *item=litem[i];
        if(visShortDistPath[i])
        {
            item->setPen(QPen(QColor("#000000"),2));
            continue;
        }
        else if(visNearPath[i])
        {
            item->setPen(QPen(QColor("#4169e1"),2));
            continue;
        }
        double fdc=1.0*Gp.E[i].flow/Gp.E[i].capacity;
        if(fdc<=0.5)item->setPen(QColor("#007f00"));
        else if(fdc<=0.8)item->setPen(QColor("#00ff00"));
        else if(fdc<=1.0)item->setPen(QColor("#ffff00"));
        else if(fdc<=1.5)item->setPen(QColor("#ff0000"));
        else item->setPen(QColor("#aa0000"));
    }
}

void MainWindow::on_pushButton_peak_clicked()
{
    auto edgeNum=Gp.getEdgeNums();
    for(int i=0;i<(int)edgeNum;i++)
    {

        Gp.E[i].flow=Gp.E[i].flow*1.4;

    }
    updatePath();

}




void MainWindow::on_pushButton_non_clicked()
{
    auto edgeNum=Gp.getEdgeNums();
    for(int i=0;i<(int)edgeNum;i++)
    {

        Gp.E[i].flow=Gp.E[i].flow*0.7;

    }
    updatePath();
}

