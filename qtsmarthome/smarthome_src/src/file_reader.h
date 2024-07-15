#ifndef FILE_READER_H
#define FILE_READER_H

#include <QObject>
#include <QFileSystemWatcher>

class FileReader : public QObject
{
    Q_OBJECT

public:
    explicit FileReader(const QString &filePath, QObject *parent = nullptr);

signals:
    void fileUpdated(const QString &content);

private slots:
    void onFileChanged(const QString &path);

private:
    QString filePath;
    QFileSystemWatcher fileWatcher;
};

#endif // FILE_READER_H
