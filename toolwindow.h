#ifndef TOOLWINDOW_H
#define TOOLWINDOW_H

#include <QWidget>
#include <qdir.h>
#include "commandlinethread.h"
#include "qprogressdialog.h"

namespace Ui {
class ToolWindow;
}

class ToolWindow : public QWidget
{
    Q_OBJECT
public:
    explicit ToolWindow(QWidget *parent = 0);
    ~ToolWindow();

private slots:
    void on_pushButton_2_clicked();
    void onCmdThreadFinished();
    void onCmdThreadStart();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

protected:
    void closeEvent(QCloseEvent *event);

private:
    CommandLineThread mCmdThread;
    QString mOpenAPKFilePath;
    QString mCurrentDir;
    QString mChooseIconPath;
    QString mChooseCornerPath;
    QString mApkIconPath;
    QString mApkDecomplePath;
    QString mAndroidManifestPath;
    QDir mApkDecompileDir;


    QPixmap chooseIconPixmap;
    QPixmap chooseCornerPixmap;


    QProgressDialog mProgressDialog;
    Ui::ToolWindow *ui;
};

#endif // TOOLWINDOW_H
