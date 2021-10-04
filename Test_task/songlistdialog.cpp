#include "songlistdialog.h"
#include "songdialog.h"
#include "ui_songlistdialog.h"

#include <QMessageBox>
#include <QFileDialog>
#include <qdebug.h>


QString filename("Save_tableView.txt");

SongListDialog::SongListDialog(QWidget *parent): QDialog(parent)
{
	m_ui = new Ui::SongListDialog();
	m_ui->setupUi(this);

    model_song = new Model_song;

    m_ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    m_ui->tableView->verticalHeader()->setDefaultSectionSize(100);

    m_ui->tableView->setModel(model_song);

    QFile file(filename);

    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        Data_song data_song;

        while(!in.atEnd())
        {
           QString line = in.readLine();
           int count = 0;

            for (QString item : line.split(";"))
            {
                if(count == 1){
                    data_song.setName(item);
                }
                if(count == 2){
                    data_song.setSinger(item);
                }
                if(count == 3){
                    data_song.setTime(item);
                }
                if(count == 4){
                    data_song.setImage(item);
                }
                count++;
            }

        model_song->addSong(data_song);
        }
    }
}

SongListDialog::~SongListDialog()
{
    delete m_ui;
}

void SongListDialog::on_btnCreate_clicked()
{
    Data_song data_song;
    SongDialog* dlg = new SongDialog(this);
    dlg->setData_song(&data_song);

    if(dlg->exec() == QDialog::Accepted)
    {
        QString temp_image_path = dlg->getImage_Path();
        QString temp_name = dlg->getName();
        QString temp_singer = dlg->getSinger();
        QString temp_time = dlg->getTime();
        QString temp_score = QString::number(dlg->getScore());

        data_song.setImage(temp_image_path);
        data_song.setName(temp_name);
        data_song.setSinger(temp_singer);
        data_song.setTime(temp_time);
        data_song.setScore(temp_score);
        model_song->addSong(data_song);
    }
    delete dlg;
}

void SongListDialog::on_btnRedact_clicked()
{
    QModelIndex index = m_ui->tableView->selectionModel()->currentIndex();

    if(index.isValid())
    {
        Data_song data_song = model_song->get_Song_data(index);
        SongDialog* dlg = new SongDialog(this);

        dlg->setData_song(&data_song);

        if(dlg->exec() == QDialog::Accepted)
        {
            QString temp_image_path = dlg->getImage_Path();
            QString temp_name = dlg->getName();
            QString temp_singer = dlg->getSinger();
            QString temp_time = dlg->getTime();
            QString temp_score = QString::number(dlg->getScore());

            data_song.setImage(temp_image_path);
            data_song.setName(temp_name);
            data_song.setSinger(temp_singer);
            data_song.setTime(temp_time);
            data_song.setScore(temp_score);

            model_song->update(m_ui->tableView->currentIndex().row(), data_song);
        }
        delete dlg;
    }
}

void SongListDialog::on_btnSave_clicked() //Save
{
    QFile file(filename);

    if(file.open( QIODevice::WriteOnly))
    {
        QTextStream ts( &file );
        QStringList strList;

        strList << "\" \"";
        for( int c = 0; c < m_ui->tableView->horizontalHeader()->count(); ++c )
            strList << "\"" + m_ui->tableView->model()->headerData(c, Qt::Horizontal).toString() + "\"";
        ts << strList.join( "|" ) + "\n";

        for( int r = 0; r < m_ui->tableView->verticalHeader()->count(); ++r )
        {
            strList.clear();
            strList << "\"" + m_ui->tableView->model()->headerData(r, Qt::Vertical).toString() + "\"";

            for( int c = 1; c < m_ui->tableView->horizontalHeader()->count(); ++c )
            {
                strList << "\"" + m_ui->tableView->model()->data(m_ui->tableView->model()->index(r, c),
                                                                    Qt::DisplayRole).toString() + "\"";
            }

            ts << strList.join( ";" ) + "\n";
        }
        file.close();

        QMessageBox::information(this, "Успех!", "Файл сохранен!");
    }
}
