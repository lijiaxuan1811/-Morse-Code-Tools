#ifndef MORSE_H
#define MORSE_H

#include <QByteArray>
#include <QMainWindow>
#include <QString>
#include <QStringList>
#include <QThread>
#include <QWidget>
#include <algorithm>
#include <windows.h>

#define di Beep(freq, time)//点信号，1倍单位长度
#define da Beep(freq, time * 3)//划信号，3倍单位长度
#define small Sleep(time)//点划之间停顿，1倍单位长度
#define large Sleep(time * 3)//字母之间停顿，3倍单位长度

QT_BEGIN_NAMESPACE
namespace Ui {
class morse;
}
QT_END_NAMESPACE

class morse : public QWidget
{
    Q_OBJECT

public:
    morse(QWidget *parent = nullptr);
    ~morse();
    static QStringList splitStringIntoChars(const QString &str) {
        QStringList chars;
        QByteArray ba = str.toUtf8();  // 将QString转换为QByteArray

        // 使用C++标准库算法std::for_each遍历ba中的每个字符
        std::for_each(ba.begin(), ba.end(), [&](char c) {
            chars.append(QString(QByteArray(1, c))); // 将每个字符作为QString添加到QStringList中
        });

        return chars;
    }

    static void toMorse(QString input, float time, int freq){
        //文字转摩尔斯电码，参数为用户输入的字符串，浮点数基准时间（单位ms，决定WPM）和整数声音频率（单位Hz）
        QStringList ch = splitStringIntoChars(input);
        for (const QString &c : ch) {
            //遍历输入字符串
            //std::cout << c.toStdString() << std::endl;
            if(c == " ") {
                //空格（单词之间）应停留7倍基准时间，但是每个单词最后一个字母已经停留了3倍，因此只需停留4倍
                Sleep(time * 4);
            }else if(c == "A" || c == "a") {
                //·-
                Beep(freq, time);//点信号长度1倍基准时间
                Sleep(time);//点划之间间隔1倍基准时间
                Beep(freq, time * 3);//划信号长度3倍基准时间
                Sleep(time * 3);//字符之间间隔3倍基准时间
            }else if(c == "B" || c == "b") {
                //-···
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time * 3);
            }else if(c == "C" || c == "c") {
                //-·-·
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time * 3);
            }else if(c == "D" || c == "d") {
                //-··
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time * 3);
            }else if(c == "E" || c == "e") {
                //·
                Beep(freq, time);
                Sleep(time * 3);
            }else if(c == "F" || c == "f") {
                //··-·
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time * 3);
            }else if(c == "G" || c == "g") {
                //--·
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time * 3);
            }else if(c == "H" || c == "h") {
                //····
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time * 3);
            }else if(c == "I" || c == "i") {
                //··
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time * 3);
            }else if(c == "J" || c == "j") {
                //·---
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time * 3);
            }else if(c == "K" || c == "k") {
                //-·-
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time * 3);
            }else if(c == "L" || c == "l") {
                //·-··
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time * 3);
            }else if(c == "M" || c == "m") {
                //--
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time * 3);
            }else if(c == "N" || c == "n") {
                //-·
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time * 3);
            }else if(c == "O" || c == "o") {
                //---
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time * 3);
            }else if(c == "P" || c == "p") {
                //·--·
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time * 3);
            }else if(c == "Q" || c == "q") {
                //--·-
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time * 3);
            }else if(c == "R" || c == "r") {
                //·-·
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time * 3);
            }else if(c == "S" || c == "s") {
                //···
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time * 3);
            }else if(c == "T" || c == "t") {
                //-
                Beep(freq, time * 3);
                Sleep(time * 3);
            }else if(c == "U" || c == "u") {
                //··-
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time * 3);
            }else if(c == "V" || c == "v") {
                //···-
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time * 3);
            }else if(c == "W" || c == "w") {
                //·--
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time * 3);
            }else if(c == "X" || c == "x") {
                //-··-
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time * 3);
            }else if(c == "Y" || c == "y") {
                //-·--
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time * 3);
            }else if(c == "Z" || c == "z") {
                //--··
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time * 3);
            }else if(c == "1") {
                //·----
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time * 3);
            }else if(c == "2") {
                //··---
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time * 3);
            }else if(c == "3") {
                //···--
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time * 3);
            }else if(c == "4") {
                //····-
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time * 3);
            }else if(c == "5") {
                //·····
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time * 3);
            }else if(c == "6") {
                //-····
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time * 3);
            }else if(c == "7") {
                //--···
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time * 3);
            }else if(c == "8") {
                //---··
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time * 3);
            }else if(c == "9") {
                //----·
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time * 3);
            }else if(c == "0") {
                //-----
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time * 3);
            }else if(c == ".") {
                //·-·-·-
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time * 3);
            }else if(c == ",") {
                //--··--
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time * 3);
            }else if(c == "?") {
                //··--··
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time * 3);
            }else if(c == "\'") {
                //·----·
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time * 3);
            }else if(c == "!") {
                //-·-·--
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time * 3);
            }else if(c == "/" || c == "\\") {
                //-··-·
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time * 3);
            }else if(c == "(") {
                //-·--·
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time * 3);
            }else if(c == ")") {
                //-·--·-
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time * 3);
            }else if(c == "&") {
                //·-···
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time * 3);
            }else if(c == ":") {
                //---···
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time * 3);
            }else if(c == ";") {
                //-·-·-·
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time * 3);
            }else if(c == "=") {
                //-···-
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time * 3);
            }else if(c == "+") {
                //·-·-·
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time * 3);
            }else if(c == "-") {
                //-····-
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time * 3);
            }else if(c == "_") {
                //··--·-
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time * 3);
            }else if(c == "\"") {
                //·-··-·
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time * 3);
            }else if(c == "$") {
                //···-··-
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time * 3);
            }else if(c == "@") {
                //·--·-·
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time);
                Beep(freq, time * 3);
                Sleep(time);
                Beep(freq, time);
                Sleep(time * 3);
            }
        }
        return;
    }

private slots:
    void on_pushButton_clicked();

private:
    Ui::morse *ui;
};
#endif // MORSE_H
