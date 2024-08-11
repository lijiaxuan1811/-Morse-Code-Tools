#ifndef MORSEWORKER_H
#define MORSEWORKER_H

#include <windows.h>
#include <QThread>
#include <QObject>
#include <QString>
#include "morse.h"

class MorseWorker : public QObject {
    Q_OBJECT
    public:
        MorseWorker(const QString &text, float baseTime, int basePitch)
            : m_text(text), m_baseTime(baseTime), m_basePitch(basePitch) {}

    public slots:
        void process() {
            morse::toMorse(m_text, m_baseTime, m_basePitch);
            emit finished();
        }

    signals:
        void finished();

    private:
        QString m_text;
        float m_baseTime;
        int m_basePitch;
};

#endif // MORSEWORKER_H
