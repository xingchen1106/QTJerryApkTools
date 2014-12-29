#include "parsemanifest.h"
#include "qfile.h"
#include <QDomDocument>
#include "QDomNodeList"
#include "qdebug.h"

const QString ParseManifest::AndroidNameSpace = "http://schemas.android.com/apk/res/android";

ParseManifest::ParseManifest(QString filename)
{
    mAndroidManifestPath = filename;
    QFile* xmlFile = new QFile(filename);
    xmlFile->open(QFile::ReadWrite | QFile::Text);
    xmlDoc.setContent(xmlFile, true);
    xmlFile->close();

    QDomNodeList manifestNode = xmlDoc.elementsByTagName("manifest");
    qDebug()<< manifestNode.length();
    QDomNode packageNode = manifestNode.at(0).attributes().namedItem("package");
    qDebug() << "The package Name is:" << packageNode.nodeValue();
    mPackageName = packageNode.nodeValue();
}

ParseManifest::~ParseManifest()
{

}

void ParseManifest::setPackageName(QString packagename)
{
    QDomNodeList manifestNode = xmlDoc.elementsByTagName("manifest");
    manifestNode.at(0).attributes().namedItem("package").setNodeValue(packagename);

    QFile savedFile(mAndroidManifestPath);
    savedFile.open(QFile::ReadWrite | QFile::Text);
    QTextStream stream( &savedFile);
    qDebug() << xmlDoc.toString();
    stream << xmlDoc.toString();
    savedFile.close();
}


QString ParseManifest::getPackageName()
{
    return mPackageName;
}

