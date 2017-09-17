#ifndef QTFIREBASEAUTH_H
#define QTFIREBASEAUTH_H
#include <QObject>

#ifdef QTFIREBASE_BUILD_AUTH
#include "src/qtfirebase.h"
#if defined(qFirebaseAuth)
#undef qFirebaseAuth
#endif
#define qFirebaseAuth (static_cast<QtFirebaseAuth *>(QtFirebaseAuth::instance()))

class QtFirebaseAuth: public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool running READ isRunning NOTIFY runningChanged)
    Q_PROPERTY(bool signedIn READ isSignedIn NOTIFY signedInChanged)
public:
    static QtFirebaseAuth *instance()
    {
        if(self == nullptr)
        {
            self = new QtFirebaseAuth(0);
        }
        return self;
    }
    enum Error{
        kAuthErrorNone,
        kAuthErrorUnimplemented,
        kAuthErrorFailure
    };
    Q_ENUM(Error)

    enum Action{
        ActRegister,
        ActSignIn,
        ActSignOut
    };
    Q_ENUM(Action)

public slots:
    //Control
    void registerUser(const QString& email, const QString& pass){Q_UNUSED(email); Q_UNUSED(pass);}
    void signIn(const QString& email, const QString& pass){Q_UNUSED(email); Q_UNUSED(pass);}
    void signOut(){}

    //Status
    bool isSignedIn() const{return false;}
    bool isRunning() const{return false;}
    int errorId() const{return kAuthErrorNone;}
    QString errorMsg() const{return QString();}

    //Data
    QString getEmail() const{return QString();}
    QString getDisplayName() const{return QString();}
    bool emailVerified() const{return false;}
    QString getPhotoUrl() const{return QString();}
    QString getUid() const{return QString();}
signals:
    void signedInChanged();
    void runningChanged();
    void completed(bool success, int actionId);
protected:
    static QtFirebaseAuth *self;
    explicit QtFirebaseAuth(QObject *parent = 0){Q_UNUSED(parent);}
    Q_DISABLE_COPY(QtFirebaseAuth)

};

#endif //QTFIREBASE_BUILD_AUTH

#endif // QTFIREBASEAUTH_H
