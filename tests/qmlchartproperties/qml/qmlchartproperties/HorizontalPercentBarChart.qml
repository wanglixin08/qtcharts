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

import QtQuick 1.0
import QtCommercial.Chart 1.1

ChartView {
    title: "Percent bar series"
    anchors.fill: parent
    theme: ChartView.ChartThemeLight
    legend.alignment: Qt.AlignBottom
    animationOptions: ChartView.SeriesAnimations

    property variant series: mySeries

    HorizontalPercentBarSeries {
        id: mySeries
        name: "bar"
        axisY: BarCategoryAxis { categories: ["2007", "2008", "2009", "2010", "2011", "2012" ] }
        BarSet { label: "Bob"; values: [2, 2, 3, 4, 5, 6]
            onClicked:                  console.log("barset.onClicked: " + index);
            onHovered:                  console.log("barset.onHovered: " + status + " " + index);
            onPenChanged:               console.log("barset.onPenChanged: " + pen);
            onBrushChanged:             console.log("barset.onBrushChanged: " + brush);
            onLabelChanged:             console.log("barset.onLabelChanged: " + label);
            onLabelBrushChanged:        console.log("barset.onLabelBrushChanged: " + labelBrush);
            onLabelFontChanged:         console.log("barset.onLabelFontChanged: " + labelFont);
            onColorChanged:             console.log("barset.onColorChanged: " + color);
            onBorderColorChanged:       console.log("barset.onBorderColorChanged: " + color);
            onLabelColorChanged:        console.log("barset.onLabelColorChanged: " + color);
            onCountChanged:             console.log("barset.onCountChanged: " + count);
            onValuesAdded:              console.log("barset.onValuesAdded: " + index + ", " + count);
            onValuesRemoved:            console.log("barset.onValuesRemoved: " + index + ", " + count);
            onValueChanged:             console.log("barset.onValuesChanged: " + index);
        }
        BarSet { label: "Susan"; values: [5, 1, 2, 4, 1, 7] }
        BarSet { label: "James"; values: [3, 5, 8, 13, 5, 8] }

        onNameChanged:              console.log("horizontalPercentBarSeries.onNameChanged: " + series.name);
        onVisibleChanged:           console.log("horizontalPercentBarSeries.onVisibleChanged: " + series.visible);
        onOpacityChanged:           console.log("horizontalPercentBarSeries.onOpacityChanged: " + opacity);
        onClicked:                  console.log("horizontalPercentBarSeries.onClicked: " + barset + " " + index);
        onHovered:                  console.log("horizontalPercentBarSeries.onHovered: " + barset
                                                + " " + status + " " + index);
        onLabelsVisibleChanged:     console.log("horizontalPercentBarSeries.onLabelsVisibleChanged: " + series.labelsVisible);
        onCountChanged:             console.log("horizontalPercentBarSeries.onCountChanged: " + count);
    }
}
