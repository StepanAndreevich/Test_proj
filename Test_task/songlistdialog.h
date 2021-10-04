#pragma once
#include <QDialog>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "model_song.h"
#include "data_song.h"

class Model_song;
class Data_song;

namespace Ui 
{
class SongListDialog;
}

class SongListDialog : public QDialog 
{
Q_OBJECT

public:
	SongListDialog(QWidget *parent = nullptr);
    ~SongListDialog();

    QString s_name;
    QString s_singer;
    QString s_time;
    QString s_preview;
    int score;
    QString str_score;

public slots:
	void on_btnCreate_clicked();

private slots:
    void on_btnRedact_clicked();
    void on_btnSave_clicked();

private:
	Ui::SongListDialog* m_ui = nullptr;
    Model_song* model_song;
    QList<Data_song>* data_song;
};
