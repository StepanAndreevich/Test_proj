#ifndef DATA_SONG_H
#define DATA_SONG_H
#pragma once

#include <QString>
#include "songdialog.h"

class Data_song
{
public:
    Data_song();

    QString getImage() const;
    void setImage(QString &value);

    QString getName() const;
    void setName(QString &value);

    QString getSinger() const;
    void setSinger(QString &value);

    QString getTime() const;
    void setTime(QString &value);

    QString getScore() const;
    void setScore(QString &value);

private:
    QString d_preview;
    QString d_name;
    QString d_singer;
    QString d_time;
    QString d_score;
};

#endif // DATA_SONG_H
