#include "mainwindow.h"
#include <qmenu.h>

//Constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setMinimumSize(WWidth, WHeight);
    setWindowTitle("File Editor");

    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    buttonInit();
    createMenu();
    createDocks();
    createTextField();
    connectSignals();
}

void MainWindow::buttonInit()
{
    //Top menu
    NewFile = new QAction(QIcon(":/Icons/new-file.png"), "Новий файл");
    OpenFile = new QAction(QIcon(":/Icons/open.png"), "Відкрити файл");
    Save = new QAction(QIcon(":/Icons/save.png"), "Зберегти");
    SaveAs = new QAction(QIcon(":/Icons/save-as.png"), "Зберегти як");
    Exit = new QAction(QIcon(":/Icons/close.png"), "Закрити програму");
    FileList.push_back(NewFile);
    FileList.push_back(OpenFile);
    FileList.push_back(Save);
    FileList.push_back(SaveAs);
    FileList.push_back(Exit);

    ClearField = new QAction(QIcon(":/Icons/clear.png"), "Очистити текстове поле");
    TextToUpper = new QAction(QIcon(":/Icons/arrow-up.png"), "У верхнiй регiстр");
    TextToLower = new QAction(QIcon(":/Icons/arrow-down.png"), "У нижній регiстр");
    TextUp = new QAction(QIcon(":/Icons/arrows-out.png"), "Збiльшити шрифт");
    TextDown = new QAction(QIcon(":/Icons/arrows-in.png"), "Зменшити шрифт");
    CheckText = new QAction(QIcon(":/Icons/check2.png"), "Провірити текст");
    EditList.push_back(ClearField);
    EditList.push_back(TextToUpper);
    EditList.push_back(TextToLower);
    EditList.push_back(TextUp);
    EditList.push_back(TextDown);
    EditList.push_back(CheckText);

    About = new QAction(QIcon(":/Icons/info.png"), "Про застосунок");
    Reference = new QAction(QIcon(":/Icons/docx.png"), "Довідка");
    HelpList.push_back(About);
    HelpList.push_back(Reference);

    //Top Dock
    NewFileButton = new QPushButton("Новий файл", this);
    NewFileButton->setIcon(QIcon(":/Icons/new-file.png"));
    NewFileButton->setMinimumSize(140, 40);
    NewFileButton->setMaximumSize(400, 40);

    OpenFileButton = new QPushButton("Відкрити файл", this);
    OpenFileButton->setIcon(QIcon(":/Icons/open.png"));
    OpenFileButton->setMinimumSize(140, 40);
    OpenFileButton->setMaximumSize(400, 40);

    SaveButton = new QPushButton("Зберегти", this);
    SaveButton->setIcon(QIcon(":/Icons/save.png"));
    SaveButton->setMinimumSize(140, 40);
    SaveButton->setMaximumSize(400, 40);

    SaveAsButton = new QPushButton("Зберегти як", this);
    SaveAsButton->setIcon(QIcon(":/Icons/save-as.png"));
    SaveAsButton->setMinimumSize(140, 40);
    SaveAsButton->setMaximumSize(400, 40);

    ExitButton = new QPushButton("Закрити програму", this);
    ExitButton->setIcon(QIcon(":/Icons/close.png"));
    ExitButton->setMinimumSize(140, 40);
    ExitButton->setMaximumSize(400, 40);

    //Right Dock
    fontSizeSpinBox = new QSpinBox(this);
    fontSizeSpinBox->setMinimumSize(40, 40);
    fontSizeSpinBox->setMaximumSize(400, 40);
    fontSizeSpinBox->setMinimum(1);

    ClearFieldButton = new QToolButton(this);
    ClearFieldButton->setText("Очистити текстове поле");
    ClearFieldButton->setIcon(QIcon(":/Icons/clear.png"));
    ClearFieldButton->setMinimumSize(40, 40);
    ClearFieldButton->setMaximumSize(400, 40);

    TextToUpperButton = new QToolButton(this);
    TextToUpperButton->setText("У верхнiй регiстр");
    TextToUpperButton->setIcon(QIcon(":/Icons/arrow-up.png"));
    TextToUpperButton->setMinimumSize(40, 40);
    TextToUpperButton->setMaximumSize(400, 40);

    TextToLowerButton = new QToolButton(this);
    TextToLowerButton->setText("У нижній регiстр");
    TextToLowerButton->setIcon(QIcon(":/Icons/arrow-down.png"));
    TextToLowerButton->setMinimumSize(40, 40);
    TextToLowerButton->setMaximumSize(400, 40);

    TextUpButton = new QToolButton(this);
    TextUpButton->setIcon(QIcon(":/Icons/arrows-out.png"));
    TextUpButton->setMinimumSize(40, 40);
    TextUpButton->setMaximumSize(400, 40);

    TextDownButton = new QToolButton(this);
    TextDownButton->setIcon(QIcon(":/Icons/arrows-in.png"));
    TextDownButton->setMinimumSize(40, 40);
    TextDownButton->setMaximumSize(400, 40);

    CheckTextButton = new QToolButton(this);
    CheckTextButton->setIcon(QIcon(":/Icons/check2.png"));
    CheckTextButton->setMinimumSize(40, 40);
    CheckTextButton->setMaximumSize(400, 40);
}

//Menu on top of app
void MainWindow::createMenu()
{
    Menu = new QMenuBar(this);
    setMenuBar(Menu);

    File = new QMenu("Файл");
    Edit = new QMenu("Редагування");
    Help = new QMenu("Допомога");

    Menu->addMenu(File);
    Menu->addMenu(Edit);
    Menu->addMenu(Help);

    File->addActions(FileList);
    Edit->addActions(EditList);
    Help->addActions(HelpList);
}

//Creating 2 Docks
void MainWindow::createDocks()
{
    /////////////////////////// TopDock

    TopDock = new QDockWidget(this);
    TopDock->setAllowedAreas(Qt::TopDockWidgetArea | Qt::RightDockWidgetArea);
    TopDock->setMaximumHeight(100);
    addDockWidget(Qt::TopDockWidgetArea, TopDock);

    QWidget *TopField = new QWidget(TopDock);

    QHBoxLayout *TopFieldLayout = new QHBoxLayout(TopField);

    TopFieldLayout->addWidget(NewFileButton);
    TopFieldLayout->addWidget(OpenFileButton);
    TopFieldLayout->addWidget(SaveButton);
    TopFieldLayout->addWidget(SaveAsButton);
    TopFieldLayout->addWidget(ExitButton);

    TopDock->setWidget(TopField);

    ///////////////////////////

    /////////////////////////// RightDock

    RightDock = new QDockWidget(this);
    RightDock->setAllowedAreas(Qt::RightDockWidgetArea);
    addDockWidget(Qt::RightDockWidgetArea, RightDock);
    RightDock->setMinimumWidth(190);
    TopDock->setFeatures(QDockWidget::NoDockWidgetFeatures);
    RightDock->setFeatures(QDockWidget::NoDockWidgetFeatures);

    QWidget *RightField = new QWidget(RightDock);

    QGridLayout *GridLayout = new QGridLayout(RightField);

    GridLayout->addWidget(fontSizeSpinBox, 0, 0);
    GridLayout->addWidget(ClearFieldButton, 0, 1);
    GridLayout->addWidget(TextToUpperButton, 1, 0);
    GridLayout->addWidget(TextToLowerButton, 1, 1);
    GridLayout->addWidget(TextUpButton, 2, 0);
    GridLayout->addWidget(TextDownButton, 2, 1);
    GridLayout->addWidget(CheckTextButton, 3, 0);

    RightDock->setWidget(RightField);

    ///////////////////////////
}

//Creating TextField at central widget
void MainWindow::createTextField()
{
    QVBoxLayout *mLayout = new QVBoxLayout;

    FileName = new QLabel("Новий файл", this);
    FileName->setMinimumSize(300, 20);

    font = QFont(FileName->font());
    font.setPointSize(16);
    FileName->setFont(font);

    FileText = new QTextEdit("", this);
    FileText->setMinimumSize(400, 400);

    mLayout->addWidget(FileName);
    mLayout->addWidget(FileText);

    centralWidget->setLayout(mLayout);
}

//Connectring singals
void MainWindow::connectSignals()
{
    /////////////
    connect(NewFile, &QAction::triggered, this, &MainWindow::signalNewFile);
    connect(NewFileButton, &QPushButton::pressed, this, &MainWindow::signalNewFile);

    connect(OpenFile, &QAction::triggered, this, &MainWindow::signalOpenFile);
    connect(OpenFileButton, &QPushButton::pressed, this, &MainWindow::signalOpenFile);

    connect(Save, &QAction::triggered, this, &MainWindow::signalSaveFile);
    connect(SaveButton, &QPushButton::pressed, this, &MainWindow::signalSaveFile);

    connect(SaveAs, &QAction::triggered, this, &MainWindow::signalSaveFileAs);
    connect(SaveAsButton, &QPushButton::pressed, this, &MainWindow::signalSaveFileAs);

    connect(Exit, &QAction::triggered, this, &MainWindow::signalExit);
    connect(ExitButton, &QPushButton::pressed, this, &MainWindow::signalExit);

    ////////////
    connect(ClearField, &QAction::triggered, this, &MainWindow::signalClearField);
    connect(ClearFieldButton, &QToolButton::pressed, this, &MainWindow::signalClearField);

    connect(TextToUpper, &QAction::triggered, this, &MainWindow::signalTextToUpper);
    connect(TextToUpperButton, &QToolButton::pressed, this, &MainWindow::signalTextToUpper);

    connect(TextToLower, &QAction::triggered, this, &MainWindow::signalTextToLower);
    connect(TextToLowerButton, &QToolButton::pressed, this, &MainWindow::signalTextToLower);

    connect(TextUp, &QAction::triggered, this, &MainWindow::signalTextUp);
    connect(TextUpButton, &QPushButton::pressed, this, &MainWindow::signalTextUp);

    connect(TextDown, &QAction::triggered, this, &MainWindow::signalTextDown);
    connect(TextDownButton, &QPushButton::pressed, this, &MainWindow::signalTextDown);

    connect(CheckText, &QAction::triggered, this, &MainWindow::signalCheckText);
    connect(CheckTextButton, &QPushButton::pressed, this, &MainWindow::signalCheckText);

    connect(FileText, &QTextEdit::textChanged, this, &MainWindow::signalTextFieldChanged);

    connect(fontSizeSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::changeFontSize);

    connect(About, &QAction::triggered, this, &MainWindow::signalShowAbout);
    connect(Reference, &QAction::triggered, this, &MainWindow::signalShowReference);
}

MainWindow::~MainWindow() {}

//////////Signals
void MainWindow::signalNewFile()
{
    FileText->clear();
    FileName->setText("Новий файл");
}

void MainWindow::signalOpenFile()
{
    QString filePath = QFileDialog::getOpenFileName(this,
                                                    "Відкрити файл",
                                                    "",
                                                    "Текстові файли (*.txt)");
    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            FileText->setText(in.readAll());

            // Отримання тільки імені файлу
            QFileInfo fileInfo(filePath);
            QString fileName = fileInfo.fileName();
            FileName->setText(fileName); // Зберігаємо тільки ім'я файлу

            QFont font = FileText->font();
            fontSizeSpinBox->setValue(font.pointSize());

            file.close();
        }
    }
}

void MainWindow::signalSaveFile()
{
    QString fileName = FileName->text();
    if (fileName.isEmpty() || fileName == "Новий файл") {
        signalSaveFileAs();
    } else {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << FileText->toPlainText();

            file.close();
        }
    }
}

void MainWindow::signalSaveFileAs()
{
    QString filePath = QFileDialog::getSaveFileName(this,
                                                    "Зберегти як",
                                                    "Новий файл",
                                                    "Текстові файли (*.txt)");
    if (!filePath.isEmpty()) {
        QFileInfo fileInfo(filePath);
        QString fileName = fileInfo.fileName();
        FileName->setText(fileName);

        signalSaveFile();
    }
}

void MainWindow::signalExit()
{
    close();
}

///////////////
void MainWindow::signalClearField()
{
    FileText->clear();
}

void MainWindow::signalTextToUpper()
{
    QString text = FileText->toPlainText();
    FileText->setText(text.toUpper());
}

void MainWindow::signalTextToLower()
{
    QString text = FileText->toPlainText();
    FileText->setText(text.toLower());
}

void MainWindow::signalTextUp()
{
    QFont font = FileText->font();
    font.setPointSize(font.pointSize() + 1);
    FileText->setFont(font);

    fontSizeSpinBox->setValue(font.pointSize());
}

void MainWindow::signalTextDown()
{
    QFont font = FileText->font();
    if(font.pointSize()>1){
        font.setPointSize(font.pointSize() - 1);
        FileText->setFont(font);
        fontSizeSpinBox->setValue(font.pointSize());
    }
}

void MainWindow::signalCheckText()
{
    QString fixedText = FileText->toPlainText();

    QRegularExpression regex(
        "([.,])(\\S)"); // Перша група — крапка або кома, друга — будь-який непробіл
    fixedText.replace(regex, "\\1 \\2"); // Заміна: після крапки/коми додаємо пробіл

    FileText->setText(fixedText);
}

void MainWindow::changeFontSize(int size) {
    QFont font = FileText->font();
    font.setPointSize(size);
    FileText->setFont(font);
}

void MainWindow::signalShowAbout()
{
    QMessageBox::about(this, "Про застосунок",
                       "Программа для редактування текстових файлів\n"
                       "Версія: 1.0\n"
                       "Рік: 2024");
}

void MainWindow::signalShowReference()
{
    QMessageBox::about(this, "Довідка",
                             "Це текст довідка про використання програми.\n"
                             "1. Новий файл: стровює новий пустий файл.\n"
                             "2. Відкрити файл: відкриває файл вибраний з системи.\n"
                             "3. Зберегти: зберігає файл(якщо файл створенний в системі).\n"
                             "4. Зберегти як: зберігає файл в новий файл.\n"
                             "5. Очистити текстове поле: очищує текстове поле.\n"
                             "6. Провірити текст: Перевiрка, що пiсля крапки/коми стоїть пробiл та виправлення за необхiдностi.");
}

void MainWindow::signalTextFieldChanged() {}
