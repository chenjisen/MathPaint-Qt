/********************************************************************************
** Form generated from reading UI file 'MathPaint_Qt.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATHPAINT_QT_H
#define UI_MATHPAINT_QT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MathPaint_QtClass
{
public:
    QWidget *centralWidget;
    QLabel *imageBox;
    QPushButton *buttonShow;
    QLabel *label;
    QLineEdit *lineEditXMin;
    QLineEdit *lineEditXMax;
    QLabel *label_2;
    QLineEdit *lineEditYMin;
    QLineEdit *lineEditYMax;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEditXCursor;
    QLabel *label_5;
    QLineEdit *lineEditYCursor;
    QPushButton *buttonReturn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MathPaint_QtClass)
    {
        if (MathPaint_QtClass->objectName().isEmpty())
            MathPaint_QtClass->setObjectName(QStringLiteral("MathPaint_QtClass"));
        MathPaint_QtClass->resize(973, 708);
        MathPaint_QtClass->setMouseTracking(true);
        centralWidget = new QWidget(MathPaint_QtClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMouseTracking(true);
        imageBox = new QLabel(centralWidget);
        imageBox->setObjectName(QStringLiteral("imageBox"));
        imageBox->setGeometry(QRect(10, 10, 644, 644));
        imageBox->setMouseTracking(true);
        imageBox->setAutoFillBackground(false);
        buttonShow = new QPushButton(centralWidget);
        buttonShow->setObjectName(QStringLiteral("buttonShow"));
        buttonShow->setGeometry(QRect(700, 450, 75, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(670, 10, 81, 31));
        lineEditXMin = new QLineEdit(centralWidget);
        lineEditXMin->setObjectName(QStringLiteral("lineEditXMin"));
        lineEditXMin->setGeometry(QRect(670, 50, 113, 20));
        lineEditXMax = new QLineEdit(centralWidget);
        lineEditXMax->setObjectName(QStringLiteral("lineEditXMax"));
        lineEditXMax->setGeometry(QRect(670, 80, 113, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(670, 110, 54, 12));
        lineEditYMin = new QLineEdit(centralWidget);
        lineEditYMin->setObjectName(QStringLiteral("lineEditYMin"));
        lineEditYMin->setGeometry(QRect(670, 130, 113, 20));
        lineEditYMax = new QLineEdit(centralWidget);
        lineEditYMax->setObjectName(QStringLiteral("lineEditYMax"));
        lineEditYMax->setGeometry(QRect(670, 160, 113, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(670, 330, 54, 12));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(670, 350, 21, 16));
        lineEditXCursor = new QLineEdit(centralWidget);
        lineEditXCursor->setObjectName(QStringLiteral("lineEditXCursor"));
        lineEditXCursor->setGeometry(QRect(690, 350, 113, 20));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(670, 380, 21, 16));
        lineEditYCursor = new QLineEdit(centralWidget);
        lineEditYCursor->setObjectName(QStringLiteral("lineEditYCursor"));
        lineEditYCursor->setGeometry(QRect(690, 380, 113, 20));
        buttonReturn = new QPushButton(centralWidget);
        buttonReturn->setObjectName(QStringLiteral("buttonReturn"));
        buttonReturn->setGeometry(QRect(700, 500, 75, 23));
        MathPaint_QtClass->setCentralWidget(centralWidget);
        buttonShow->raise();
        imageBox->raise();
        label->raise();
        lineEditXMin->raise();
        lineEditXMax->raise();
        label_2->raise();
        lineEditYMin->raise();
        lineEditYMax->raise();
        label_3->raise();
        label_4->raise();
        lineEditXCursor->raise();
        label_5->raise();
        lineEditYCursor->raise();
        buttonReturn->raise();
        menuBar = new QMenuBar(MathPaint_QtClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 973, 23));
        MathPaint_QtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MathPaint_QtClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(true);
        MathPaint_QtClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MathPaint_QtClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MathPaint_QtClass->setStatusBar(statusBar);

        retranslateUi(MathPaint_QtClass);
        QObject::connect(buttonShow, SIGNAL(clicked()), MathPaint_QtClass, SLOT(showClicked()));

        QMetaObject::connectSlotsByName(MathPaint_QtClass);
    } // setupUi

    void retranslateUi(QMainWindow *MathPaint_QtClass)
    {
        MathPaint_QtClass->setWindowTitle(QApplication::translate("MathPaint_QtClass", "MathPaint_Qt", Q_NULLPTR));
        imageBox->setText(QApplication::translate("MathPaint_QtClass", "ImageBox", Q_NULLPTR));
        buttonShow->setText(QApplication::translate("MathPaint_QtClass", "\346\230\276\347\244\272\345\233\276\345\275\242", Q_NULLPTR));
        label->setText(QApplication::translate("MathPaint_QtClass", "x\347\232\204\350\214\203\345\233\264", Q_NULLPTR));
        label_2->setText(QApplication::translate("MathPaint_QtClass", "y\347\232\204\350\214\203\345\233\264", Q_NULLPTR));
        label_3->setText(QApplication::translate("MathPaint_QtClass", "\345\205\211\346\240\207\344\275\215\347\275\256", Q_NULLPTR));
        label_4->setText(QApplication::translate("MathPaint_QtClass", "x=", Q_NULLPTR));
        label_5->setText(QApplication::translate("MathPaint_QtClass", "y=", Q_NULLPTR));
        buttonReturn->setText(QApplication::translate("MathPaint_QtClass", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MathPaint_QtClass: public Ui_MathPaint_QtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATHPAINT_QT_H
