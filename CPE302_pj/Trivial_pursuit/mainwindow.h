#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "filereader.h"
#include "filewriter.h"
#include "gamefunctions.h"
#include "gamesetup.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_rollDiceButton_clicked();
    void on_submitAnswerButton_clicked();

private:
    Ui::MainWindow *ui;
    GameSetup *gameSetup;
};

#endif // MAINWINDOW_H
