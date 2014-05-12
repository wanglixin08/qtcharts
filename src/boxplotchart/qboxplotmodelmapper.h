/****************************************************************************
**
** Copyright (C) 2014 Digia Plc
** All rights reserved.
** For any questions to Digia, please use contact form at http://qt.digia.com
**
** This file is part of the Qt Enterprise Charts Add-on.
**
** $QT_BEGIN_LICENSE$
** Licensees holding valid Qt Enterprise licenses may use this file in
** accordance with the Qt Enterprise License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.
**
** If you have questions regarding the use of this file, please use
** contact form at http://qt.digia.com
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QBOXPLOTMODELMAPPER_H
#define QBOXPLOTMODELMAPPER_H

#include "qchartglobal.h"
#include <QObject>

class QAbstractItemModel;

QTCOMMERCIALCHART_BEGIN_NAMESPACE

class QBoxPlotModelMapperPrivate;
class QBoxPlotSeries;

class QTCOMMERCIALCHART_EXPORT QBoxPlotModelMapper : public QObject
{
    Q_OBJECT

protected:
    explicit QBoxPlotModelMapper(QObject *parent = 0);

    QAbstractItemModel *model() const;
    void setModel(QAbstractItemModel *model);

    QBoxPlotSeries *series() const;
    void setSeries(QBoxPlotSeries *series);

    int first() const;
    void setFirst(int first);

    int count() const;
    void setCount(int count);

    int firstBoxSetSection() const;
    void setFirstBoxSetSection(int firstBoxSetSection);

    int lastBoxSetSection() const;
    void setLastBoxSetSection(int lastBoxSetSection);

    Qt::Orientation orientation() const;
    void setOrientation(Qt::Orientation orientation);

protected:
    QBoxPlotModelMapperPrivate * const d_ptr;
    Q_DECLARE_PRIVATE(QBoxPlotModelMapper)
};

QTCOMMERCIALCHART_END_NAMESPACE

#endif // QBOXPLOTMODELMAPPER_H
