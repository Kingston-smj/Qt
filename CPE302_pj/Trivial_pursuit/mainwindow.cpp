#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString playerName = "Player";
    int maxLives = 3;
    int maxQuestions = 10;

    gameSetup = new GameSetup(playerName.toStdString(), maxLives, maxQuestions);

    // Initial UI setup
    ui->labelScore->setText("Score: 0");
    ui->labelLives->setText("Lives: 3");
    ui->labelQuestion->setText("Press 'Roll Dice' to start!");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete gameSetup;
}

void MainWindow::on_rollDiceButton_clicked()
{
    auto qna = gameSetup->startRound();
    ui->labelQuestion->setText(QString::fromStdString(qna.first));
}

void MainWindow::on_submitAnswerButton_clicked()
{
    QString userAnswer = ui->lineEditAnswer->text();
    bool isCorrect = gameSetup->submitAnswer(userAnswer.toStdString());

    if (isCorrect) {
        ui->labelFeedback->setText("Correct!");
    } else {
        ui->labelFeedback->setText("Incorrect!");
    }

    ui->labelScore->setText("Score: " + QString::number(gameSetup->getScore()));
    ui->labelLives->setText("Lives: " + QString::number(gameSetup->getLives()));

    if (gameSetup->isGameOver()) {
        ui->labelQuestion->setText("Game Over!");
        ui->rollDiceButton->setEnabled(false);
        ui->submitAnswerButton->setEnabled(false);
    }
}
