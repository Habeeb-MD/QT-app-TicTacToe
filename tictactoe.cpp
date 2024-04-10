#include "tictactoe.h"
#include "./ui_tictactoe.h"

TicTacToe::TicTacToe(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::TicTacToe), moveNumber(0), gameInProgess(true)
{
    ui->setupUi(this);
    board[0][0] = ui->row0col0;
    board[0][1] = ui->row0col1;
    board[0][2] = ui->row0col2;
    board[1][0] = ui->row1col0;
    board[1][1] = ui->row1col1;
    board[1][2] = ui->row1col2;
    board[2][0] = ui->row2col0;
    board[2][1] = ui->row2col1;
    board[2][2] = ui->row2col2;
    ui->resultText->setStyleSheet("font-family:'Sans Serif'; font-size:19pt; font-weight:400; font-style:normal;");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j]->setStyleSheet("font-family:'Sans Serif'; font-size:16pt; font-weight:400; font-style:normal;");
        }
    }
}

TicTacToe::~TicTacToe()
{
    delete ui;
}

void TicTacToe::checkWinner()
{
    int winner = -1;
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0]->text() == board[i][1]->text() && board[i][0]->text() == board[i][2]->text())
        {
            if (board[i][0]->text() == "O")
                winner = 0;
            if (board[i][0]->text() == "X")
                winner = 1;
        }
        if (board[0][i]->text() == board[1][i]->text() && board[0][i]->text() == board[2][i]->text())
        {
            if (board[0][i]->text() == "O")
                winner = 0;
            if (board[0][i]->text() == "X")
                winner = 1;
        }
    }
    if (board[0][0]->text() == board[1][1]->text() && board[0][0]->text() == board[2][2]->text())
    {
        if (board[0][0]->text() == "O")
            winner = 0;
        if (board[0][0]->text() == "X")
            winner = 1;
    }
    if (board[0][2]->text() == board[1][1]->text() && board[0][2]->text() == board[2][0]->text())
    {
        if (board[0][2]->text() == "O")
            winner = 0;
        if (board[0][2]->text() == "X")
            winner = 1;
    }
    if (winner == 1)
    {
        this->gameInProgess = false;
        ui->resultText->setText("Player 1 Win");
    }
    else if (winner == 0)
    {
        this->gameInProgess = false;
        ui->resultText->setText("Player 2 Win");
    }
    else if (this->moveNumber == 9)
    {
        this->gameInProgess = false;
        ui->resultText->setText("Draw");
    }
    ui->resultText->setAlignment(Qt::AlignCenter);
}

void TicTacToe::handle_click(QPushButton *btn)
{
    if (!this->gameInProgess)
        return;

    QString Value = btn->text();
    if (Value.isEmpty())
    {
        if (this->moveNumber % 2 == 0)
        {
            btn->setText("X");
        }
        else
        {
            btn->setText("O");
        }
        this->moveNumber += 1;
        checkWinner();
    }
}
void TicTacToe::on_row0col0_clicked()
{
    handle_click(ui->row0col0);
}

void TicTacToe::on_row0col1_clicked()
{
    handle_click(ui->row0col1);
}

void TicTacToe::on_row0col2_clicked()
{
    handle_click(ui->row0col2);
}

void TicTacToe::on_row1col0_clicked()
{
    handle_click(ui->row1col0);
}

void TicTacToe::on_row1col1_clicked()
{
    handle_click(ui->row1col1);
}

void TicTacToe::on_row1col2_clicked()
{
    handle_click(ui->row1col2);
}

void TicTacToe::on_row2col0_clicked()
{
    handle_click(ui->row2col0);
}

void TicTacToe::on_row2col1_clicked()
{
    handle_click(ui->row2col1);
}

void TicTacToe::on_row2col2_clicked()
{
    handle_click(ui->row2col2);
}

void TicTacToe::on_resetButton_clicked()
{
    this->moveNumber = 0;
    this->gameInProgess = true;
    ui->resultText->setText("");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            board[i][j]->setText("");
        }
    }
}
