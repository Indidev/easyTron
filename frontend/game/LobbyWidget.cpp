#include "LobbyWidget.h"
#include "ui_LobbyWidget.h"

LobbyWidget::LobbyWidget() :
    ui(new Ui::LobbyWidget)
{
    ui->setupUi(this);
    connect(ui->exitBtn, SIGNAL(clicked()), this, SIGNAL(c_exit()));
    connect(ui->goBtn, SIGNAL(clicked()), this, SIGNAL(c_go()));

    ui->contentTable->verticalHeader()->setVisible(false);
    enableGoButton(false);
}

LobbyWidget::~LobbyWidget()
{
    delete ui;
}

void LobbyWidget::updateTable(QList<RowData *> &rows)
{
    ui->contentTable->setRowCount(rows.size() + 1);
    ui->contentTable->clearContents();

    for (int i = 0; i < rows.size(); i++) {

        QPixmap colorPixmap(130, 130);
        colorPixmap.fill(QColor(rows[i]->color));
        QPainter p(&colorPixmap);
        p.drawRect(1, 1, colorPixmap.width() - 2, colorPixmap.height() - 2);
        p.end();

        QIcon colorItem;
        colorItem.addPixmap(colorPixmap);
        ui->contentTable->setItem(i, 0, new QTableWidgetItem(rows[i]->controller->getName()));
        ui->contentTable->setItem(i, 1, new QTableWidgetItem(colorItem, ""));
        ui->contentTable->setItem(i, 2, new QTableWidgetItem(rows[i]->controller->toString()));
        ui->contentTable->setItem(i, 3, new QTableWidgetItem(rows[i]->status));

        for (int r = 0; r < 4; r++) {
            QTableWidgetItem *item = ui->contentTable->item(i, r);
            item->setTextColor(Qt::white);
            item->setBackgroundColor(QColor(255, 255, 255, 50));
        }
    }

    QTableWidgetItem *lastRow = new QTableWidgetItem("Up: Join, Down: Leave, Left/Right: Change color");
    lastRow->setTextColor(Qt::gray);
    ui->contentTable->setItem(rows.size(), 3, lastRow);
}

void LobbyWidget::enableGoButton(bool enabled)
{
    ui->goBtn->setEnabled(enabled);
}


