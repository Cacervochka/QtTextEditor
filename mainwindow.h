#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDockWidget>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QFont>
#include <QFile>
#include <QFileDialog>
#include <QFontMetrics>
#include <QRegularExpression>
#include <QToolButton>
#include <QComboBox>
#include <QSpinBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void buttonInit();

    void createMenu();
    bool deleteMenu();

    void createDocks();
    bool deleteDocks();

    void createTextField();
    bool deleteTextField();

    void connectSignals();

private:
    QMenuBar* Menu;
    QMenu* File;
    QMenu* Edit;
    QMenu* Help;
    QList<QAction*> FileList;
    QList<QAction*> EditList;
    QList<QAction*> HelpList;

    QAction* NewFile;
    QAction* OpenFile;
    QAction* Save;
    QAction* SaveAs;
    QAction* Exit;

    QPushButton* NewFileButton;
    QPushButton* OpenFileButton;
    QPushButton* SaveButton;
    QPushButton* SaveAsButton;
    QPushButton* ExitButton;

    QAction* ClearField;
    QAction* TextToUpper;
    QAction* TextToLower;
    QAction* TextUp;
    QAction* TextDown;
    QAction* CheckText;

    QSpinBox* fontSizeSpinBox;
    QToolButton* ClearFieldButton;
    QToolButton* TextToUpperButton;
    QToolButton* TextToLowerButton;
    QToolButton* TextUpButton;
    QToolButton* TextDownButton;
    QToolButton* CheckTextButton;

    QAction* About;
    QAction* Reference;

    QDockWidget* TopDock;
    QDockWidget* RightDock;

    QTextEdit* FileText;
    QLabel* FileName;
    QFont font;

    QWidget* centralWidget;

    unsigned int WHeight=600,WWidth=900;

private slots:
    //////////
    void signalNewFile();

    void signalOpenFile();

    void signalSaveFile();

    void signalSaveFileAs();

    void signalExit();

    ///////////////
    void signalClearField();

    void signalTextToUpper();

    void signalTextToLower();

    void signalTextUp();

    void signalTextDown();

    void signalCheckText();

    void changeFontSize(int size);

    void signalTextFieldChanged();
};


#endif // MAINWINDOW_H
