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

#include "qboxplotlegendmarker.h"
#include "qboxplotlegendmarker_p.h"
#include "qboxplotseries.h"
#include "qboxplotseries_p.h"

QTCOMMERCIALCHART_BEGIN_NAMESPACE

/*!
    \class QBoxPlotLegendMarker
    \inmodule Qt Charts
    \brief QBoxPlotLegendMarker object
    \mainclass

    QBoxPlotLegendMarker is related to QBoxPlotSeries classes.

    \sa QLegend, QBoxPlotSeries
*/

/*!
  \fn virtual LegendMarkerType QBoxPlotLegendMarker::type()
  Returns QLegendMarker::LegendMarkerTypeBoxPlot
*/

/*!
  \internal
*/
QBoxPlotLegendMarker::QBoxPlotLegendMarker(QBoxPlotSeries *series, QLegend *legend, QObject *parent) :
    QLegendMarker(*new QBoxPlotLegendMarkerPrivate(this,series,legend), parent)
{
    d_ptr->updated();
}

/*!
  Destructor
*/
QBoxPlotLegendMarker::~QBoxPlotLegendMarker()
{
}

/*!
    \internal
*/
QBoxPlotLegendMarker::QBoxPlotLegendMarker(QBoxPlotLegendMarkerPrivate &d, QObject *parent) :
    QLegendMarker(d, parent)
{
}

/*!
  Returns the related series
*/
QBoxPlotSeries* QBoxPlotLegendMarker::series()
{
    Q_D(QBoxPlotLegendMarker);
    return d->m_series;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

QBoxPlotLegendMarkerPrivate::QBoxPlotLegendMarkerPrivate(QBoxPlotLegendMarker *q, QBoxPlotSeries *series, QLegend *legend) :
    QLegendMarkerPrivate(q,legend),
    q_ptr(q),
    m_series(series)
{
    QObject::connect(m_series, SIGNAL(nameChanged()), this, SLOT(updated()));
    QObject::connect(m_series->d_func(), SIGNAL(updated()), this, SLOT(updated()));
}

QBoxPlotLegendMarkerPrivate::~QBoxPlotLegendMarkerPrivate()
{
}

QAbstractSeries* QBoxPlotLegendMarkerPrivate::series()
{
    return m_series;
}

QObject* QBoxPlotLegendMarkerPrivate::relatedObject()
{
    return m_series;
}

void QBoxPlotLegendMarkerPrivate::updated()
{
    bool labelChanged = false;
    bool brushChanged = false;

    if (!m_customLabel && (m_item->label() != m_series->name())) {
        m_item->setLabel(m_series->name());
        labelChanged = true;
    }
    if (!m_customBrush && (m_item->brush() != m_series->brush())) {
        m_item->setBrush(m_series->brush());
        brushChanged = true;
    }
    invalidateLegend();

    if (labelChanged)
        emit q_ptr->labelChanged();
    if (brushChanged)
        emit q_ptr->brushChanged();
}

#include "moc_qboxplotlegendmarker.cpp"
#include "moc_qboxplotlegendmarker_p.cpp"

QTCOMMERCIALCHART_END_NAMESPACE

