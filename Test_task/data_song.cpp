#include "data_song.h"
#include <QFileDialog>

Data_song::Data_song()
{
    this->d_preview = d_preview;
    this->d_name = d_name;
    this->d_singer = d_singer;
    this->d_time = d_time;
    this->d_score = d_score;
}

QString Data_song::getImage() const
{
    return this->d_preview;
}

QString Data_song::getName() const
{
    return this->d_name;
}

QString Data_song::getSinger() const
{
    return this->d_singer;
}

QString Data_song::getTime() const
{
    return this->d_time;
}

QString Data_song::getScore() const
{
    return this->d_score;
}

void Data_song::setImage(QString &value)
{
    this->d_preview = value;
}

void Data_song::setName(QString &value)
{
    this->d_name = value;
}

void Data_song::setSinger(QString &value)
{
    this->d_singer = value;
}

void Data_song::setTime(QString &value)
{
    this->d_time = value;
}

void Data_song::setScore(QString &value)
{
    this->d_score = value;
}
