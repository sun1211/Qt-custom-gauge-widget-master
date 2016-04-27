/***************************************************************************
**                                                                        **
**  QcGauge, for instrumentation, and real time data measurement          **
**  visualization widget for Qt.                                          **
**  Copyright (C) 2015 Hadj Tahar Berrima                                 **
**                                                                        **
**  This program is free software: you can redistribute it and/or modify  **
**  it under the terms of the GNU Lesser General Public License as        **
**  published by the Free Software Foundation, either version 3 of the    **
**  License, or (at your option) any later version.                       **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
**  GNU Lesser General Public License for more details.                   **
**                                                                        **
**  You should have received a copy of the GNU Lesser General Public      **
**  License along with this program.                                      **
**  If not, see http://www.gnu.org/licenses/.                             **
**                                                                        **
****************************************************************************
**           Author:  Hadj Tahar Berrima                                  **
**           Website: http://pytricity.com/                               **
**           Contact: berrima_tahar@yahoo.com                             **
**           Date:    1 dec 2014                                          **
**           Version:  1.0                                                **
****************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mSpeedGauge = new QcGaugeWidget;
    mSpeedGauge->addBackground(99);
    QcBackgroundItem *bkg1 = mSpeedGauge->addBackground(97);
    bkg1->clearrColors();
    bkg1->addColor(1,Qt::black);

    QcBackgroundItem *bkg2 = mSpeedGauge->addBackground(20);
    bkg2->clearrColors();
    bkg2->addColor(1,Qt::white);

    QcBackgroundItem *bkg3 = mSpeedGauge->addBackground(19);
    bkg3->clearrColors();
    bkg3->addColor(1,QColor(0,26,43));

    QcBackgroundItem *bkg4 = mSpeedGauge->addBackground(7);
    bkg4->clearrColors();
    bkg4->addColor(1,Qt::white);

    mSpeedGauge->addArc(96);
    mSpeedGauge->addColorBand(85);
    mSpeedGauge->addDegrees(65)->setValueRange(0,80);
    mSpeedGauge->addValues(50)->setValueRange(0,80);
    mSpeedGauge->addLabel(70)->setText("Km/h");
    QcLabelItem *lab = mSpeedGauge->addLabel(40);
    lab->setText("0");
    mSpeedNeedle = mSpeedGauge->addNeedle(70);
    mSpeedNeedle->setLabel(lab);
    mSpeedNeedle->setColor(QColor(243,83,50));
    mSpeedNeedle->setValueRange(0,80);
    mSpeedNeedle->setNeedle(QcNeedleItem::TriangleNeedle);
    ui->verticalLayout->addWidget(mSpeedGauge);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    mSpeedNeedle->setCurrentValue(value);
}
