#ifndef MODEL_SONG_H
#define MODEL_SONG_H
#pragma once

#include <QAbstractTableModel>
#include <QModelIndex>
#include <QIcon>
#include "data_song.h"

class Data_song;

class Model_song : public QAbstractTableModel {
    Q_OBJECT
public:
    Model_song( QObject* parent = 0 );
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;

    QVariant data(const QModelIndex &index, int role) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    void update(int idx, Data_song value);
    Qt::ItemFlags flags( const QModelIndex& index ) const;
    Data_song& get_Song_data(const QModelIndex & index) const;

    void addSong(Data_song& newSong);

private:
    QList<Data_song>* value;
    QVariant getData(int num_row, int position) const;
    QVariant getData_Image(int num_row, int position) const;
    QVariant getData_Score(int num_row, int position) const;
};

#endif // MODEL_SONG_H
