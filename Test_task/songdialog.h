#pragma once
#include <QDialog>
#include "songlistdialog.h"
#include "data_song.h"

class Data_song;

namespace Ui 
{	
class SongDialog;
}

class SongDialog : public QDialog
{
	Q_OBJECT
public:
	SongDialog(QWidget* parent = nullptr);
	~SongDialog();

    void Test_picture(QString picture);
    QString getFullImagePath(const QString& path) const;
    QString fullImagePath(const QString& relativePath) const;

    QString getName() const;
    QString getSinger() const;
    QString getTime() const;
    QString getImage_Path() const;
    int getScore() const;

    void setData_song(Data_song* data_song);


private slots:
    void on_buttonBox_accepted();

    void on_horizontalSlider_valueChanged(int value);

private:
	void choosePreview();
	QString copiedPreview(const QString& filePath) const;
	void showPreview(const QString& relativePath) const;
    //QString fullImagePath(const QString& relativePath) const;
	
	Ui::SongDialog* m_ui = nullptr;
	const QString m_imageDir = "../../images";

    QString f_name;
    QString f_singer;
    QString f_time;
    QString f_preview;
    QImage f_image;
    int slider;
};

