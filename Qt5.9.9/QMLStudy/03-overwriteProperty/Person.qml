import QtQuick 2.0

Display {
    property string title
    property string firstName
    property string lastName

    function fullName()
    {
        return title + " " + firstName+ " "+lastName
    }
}
