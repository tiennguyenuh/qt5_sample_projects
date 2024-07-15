#include "file_reader.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

FileReader::FileReader(const QString &filePath, QObject *parent)
    : QObject(parent), filePath(filePath)
{
    connect(&fileWatcher, &QFileSystemWatcher::fileChanged, this, &FileReader::onFileChanged);
    fileWatcher.addPath(filePath);
    qDebug() << "FileReader constructed. Watching file:" << filePath;
}

void FileReader::onFileChanged(const QString &path)
{
    qDebug() << "onFileChanged method called for path:" << path;
    if (path == this->filePath)
    {
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file);
            QString content = in.readAll();
            file.close();
            qDebug() << "File content:" << content;

            emit fileUpdated(content);

            // Re-add the file to the watcher, since QFileSystemWatcher stops watching after a file change
            fileWatcher.addPath(filePath);
        }
        else
        {
            qDebug() << "Failed to open file:" << filePath;
        }
    }
}
