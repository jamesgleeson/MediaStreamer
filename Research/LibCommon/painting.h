#ifndef PAINTING_H
#define PAINTING_H

#include <LibCommon_global.h>
#include <QString>
#include <QDataStream>
#include <inttypes.h>

class LIBCOMMONSHARED_EXPORT Painting {

public:

    Painting();

    Painting( const QString &title, const QString &artist, int year );

    void setTitle( const QString &title );
    QString getTitle() const;

    void setArtist( const QString &artist );
    QString getArtist() const;

    void setYear( int year );
    int getYear() const;

private:
    QString myArtist;
    QString myTitle;
    int     myYear;

};

LIBCOMMONSHARED_EXPORT QDataStream &operator<<( QDataStream &out, const Painting &painting );
LIBCOMMONSHARED_EXPORT QDataStream &operator>>( QDataStream &in, Painting &painting );

#endif // PAINTING_H
