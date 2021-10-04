#include "songdialog.h"
#include "ui_songdialog.h"
#include <QFileDialog>

SongDialog::SongDialog(QWidget* parent): QDialog(parent), m_ui(new Ui::SongDialog())
{
	m_ui->setupUi(this);

	connect(m_ui->btnPreview, &QPushButton::clicked, this, &SongDialog::choosePreview);
	QDir dir;
	if (!dir.exists(m_imageDir))
		dir.mkpath(m_imageDir);
}

SongDialog::~SongDialog()
{
    delete m_ui;
}

void SongDialog::choosePreview()
{
    const auto filename = QFileDialog::getOpenFileName(this, tr("Select image"), //Выберите изображение
		QString(), "(*.jpeg *.jpg *png *gif)");
	if (filename.isEmpty())
		return;

    const QString copyName = copiedPreview(filename);

    f_preview = filename;//передаем путь к изображению

	showPreview(copyName);
}

QString SongDialog::copiedPreview(const QString& filePath) const
{
    const QImage image(filePath);
    const auto smaller = image.scaled(m_ui->labelPreview->width(), m_ui->labelPreview->height(),
        Qt::AspectRatioMode::KeepAspectRatioByExpanding);

    QString name = "1.png";
    if (!smaller.save(fullImagePath(name), "PNG"))
        return QString();

    return  name;
}

void SongDialog::showPreview(const QString& relativePath) const //показать превью в диалоговом окне
{
    if (relativePath.isEmpty())
        return;
    const auto fn = fullImagePath(relativePath);
    if (!QFile::exists(fn))
        return;

    const QPixmap pixmap(fn);
    m_ui->labelPreview->setPixmap(pixmap);
}


QString SongDialog::fullImagePath(const QString& relativePath) const
{
	QDir dir;
	dir.cd(m_imageDir);
	return dir.absoluteFilePath(relativePath);
}

void SongDialog::on_buttonBox_accepted() // Press button OK
{
    f_name = m_ui->lineEdit_name->text();
    f_singer = m_ui->lineEdit_singer->text();
    f_time = m_ui->lineEdit_time->text();
}

QString SongDialog::getFullImagePath(const QString &path) const
{
    const auto temp = fullImagePath(path);
    return temp;
}

QString SongDialog::getName() const
{
    return f_name;
}

QString SongDialog::getSinger() const
{
    return f_singer;
}

QString SongDialog::getTime() const
{
    return f_time;
}

QString SongDialog::getImage_Path() const
{
    return f_preview;
}

int SongDialog::getScore() const
{
    return slider;
}

void SongDialog::setData_song(Data_song *data_song)
{
    showPreview(data_song->getImage());

    m_ui->lineEdit_name->setText(data_song->getName());
    m_ui->lineEdit_singer->setText(data_song->getSinger());
    m_ui->lineEdit_time->setText(data_song->getTime());
    m_ui->horizontalSlider->setValue(data_song->getScore().toInt());
}


void SongDialog::on_horizontalSlider_valueChanged(int value)// Передаем данные со слайдера (Horizontal Slider)
{
    slider = value;
}




