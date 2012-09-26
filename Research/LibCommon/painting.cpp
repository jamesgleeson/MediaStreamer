#include <painting.h>

Painting::Painting() {
    this->myYear = 0;
}

Painting::Painting( const QString &title, const QString &artist, int year ) {
    this->myArtist = artist;
    this->myTitle = title;
    this->myYear = year;
}

void Painting::setTitle( const QString &title ) {
    this->myTitle = title;
}

QString Painting::getTitle() const {
    return this->myTitle;
}

void Painting::setArtist( const QString &artist ) {
    this->myArtist = artist;
}

QString Painting::getArtist() const {
    return this->myArtist;
}

void Painting::setYear( int year ) {
    this->myYear = year;
}

int Painting::getYear() const {
    return this->myYear;
}

QDataStream &operator<<( QDataStream &out, const Painting &painting) {
    out << painting.getTitle()
        << painting.getArtist()
        << quint32( painting.getYear() );

    return out;
}

QDataStream &operator>>( QDataStream &in, Painting &painting ) {

    QString title;
    QString artist;
    quint32 year;

    in >> title >> artist >> year;

    painting = Painting( title, artist, year );

    return in;
}
