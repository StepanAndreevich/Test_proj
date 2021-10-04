#include "model_song.h"

Model_song:: Model_song (QObject *parent)
    : QAbstractTableModel(parent)
{
    value = new QList<Data_song>();
}

int Model_song::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED( parent )
    return value->count();
}

int Model_song::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED( parent )
    return 4;
}

QVariant Model_song::data(const QModelIndex &index, int role) const
{
    if(index.isValid() && role == Qt::DecorationRole)
        return getData_Image(index.row(), index.column());

    if (index.isValid() && role == Qt::DisplayRole)
        return getData(index.row(), index.column());

    if(index.isValid() && role == Qt::ToolTipRole)
        return getData_Score(index.row(), index.column());

    return QVariant();
}

QVariant Model_song::getData(int num_row, int position) const
{
    switch(position)
    {
    case 1:
        return QVariant(this->value->at(num_row).getName());
    case 2:
        return QVariant(this->value->at(num_row).getSinger());
    case 3:
        return QVariant(this->value->at(num_row).getTime());
    case 4:
        return QVariant(this->value->at(num_row).getImage());
    }
}

QVariant Model_song::getData_Image(int num_row, int position) const
{
    switch(position)
    {
    case 0:
        QString temp_str = this->value->at(num_row).getImage();
        QPixmap temp_image(temp_str);
        QSize PicSize(100, 100);

        temp_image = temp_image.scaled(PicSize, Qt::KeepAspectRatio);

        return temp_image;
    }
}

QVariant Model_song::getData_Score(int num_row, int position) const
{
    QString rating = this->value->at(num_row).getScore();
    QString temp_score("Song rating is: " + rating);

    return temp_score;
}

QVariant Model_song::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();
    if (orientation == Qt::Vertical)
        return QVariant(section + 1);
    else
        switch (section) {
            case 0:
                return QVariant("Preview");
            case 1:
                return QVariant("Name of song");
            case 2:
                return QVariant("Singer");
            case 3:
                return QVariant("Time");
            default:
                return QVariant();
        }
}

void Model_song::update(int idx, Data_song d_value)
{
    (*this->value)[idx] = d_value;

    QModelIndex item_idx_s = this->index(idx,0);
    QModelIndex item_idx_e = this->index(idx,this->columnCount(QModelIndex()));

    emit this->dataChanged(item_idx_s ,item_idx_e );
}

Qt::ItemFlags Model_song::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::NoItemFlags;
    return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}

Data_song &Model_song::get_Song_data(const QModelIndex &index) const
{
    return (*value)[index.row()];
}

//QList<Data_song> Model_song::getData_List() const
//{
//    return value;
//}

void Model_song::addSong(Data_song& newSong)
{
    beginInsertRows(QModelIndex(), value->size(), value->size());
        value->append(newSong);
        endInsertRows();
}
