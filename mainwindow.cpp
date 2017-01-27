#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rsa.h"
//*************************************************************************************************

//*************************************************************************************************
void MainWindow::workEntries(void)
 {
    double temp = 0;
     ui->modulus->display(ui->qprime->text().toInt() * ui->pprime->text().toInt());
     ui->znumber->display((ui->qprime->text().toInt()-1)*(ui->pprime->text().toInt()-1));

    if (primeTest(ui->pprime->text().toInt())) ui->pvalid->setChecked(true);
    if (primeTest(ui->qprime->text().toInt())) ui->qvalid->setChecked(true);

    if((long long int)ui->znumber->value() % ui->codeKey->text().toInt())
     {
         temp = ExtendedEuclidian((long long int)ui->znumber->value(), ui->codeKey->text().toInt());
         ui->relative->setChecked(true);
    }
    else
        ui->relative->setChecked(false);

     ui->secretKey->display( temp);
     temp = modulus((long long int) ui->message->text().toInt(), ui->codeKey->text().toInt(), ( long long  int) ui->modulus->value());
     while (temp < 1) temp = temp + ( long long  int) ui->modulus->value();
     ui->code->display(temp);
 }
//*************************************************************************************************

//*************************************************************************************************
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    workEntries();
}
//*************************************************************************************************

//*************************************************************************************************
MainWindow::~MainWindow()
{
    delete ui;
}
//*************************************************************************************************

//*************************************************************************************************
void MainWindow::on_pprime_returnPressed() {  ui->pvalid->setChecked(false); ui->qvalid->setChecked(false);  workEntries();}
void MainWindow::on_message_returnPressed() {  ui->pvalid->setChecked(false); ui->qvalid->setChecked(false);  workEntries(); }
void MainWindow::on_codeKey_returnPressed() {  ui->pvalid->setChecked(false); ui->qvalid->setChecked(false);  workEntries(); }
void MainWindow::on_qprime_returnPressed() {  ui->pvalid->setChecked(false); ui->qvalid->setChecked(false);  workEntries(); }
//*************************************************************************************************

//*************************************************************************************************

void MainWindow::on_modulus_overflow()
{

}
