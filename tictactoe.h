#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class TicTacToe;
}
QT_END_NAMESPACE

class TicTacToe : public QMainWindow
{
    Q_OBJECT

public:
    TicTacToe(QWidget *parent = nullptr);
    ~TicTacToe();

private slots:
    void on_row0col0_clicked();
    void on_row0col1_clicked();
    void on_row0col2_clicked();
    void on_row1col0_clicked();
    void on_row1col1_clicked();
    void on_row1col2_clicked();
    void on_row2col0_clicked();
    void on_row2col1_clicked();
    void on_row2col2_clicked();
    void on_resetButton_clicked();

private:
    Ui::TicTacToe *ui;
    int moveNumber;
    bool gameInProgess;
    QPushButton *board[3][3];
    void handle_click(QPushButton *btn);
    void checkWinner();
};
#endif // TICTACTOE_H
