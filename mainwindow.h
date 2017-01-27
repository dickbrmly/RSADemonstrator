#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void workEntries(void);

private slots:
    void on_pprime_returnPressed();

    void on_message_returnPressed();

    void on_codeKey_returnPressed();

    void on_qprime_returnPressed();

    void on_modulus_overflow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
