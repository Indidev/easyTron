#include "LobbyWidget.h"
#include "ui_LobbyWidget.h"

LobbyWidget::LobbyWidget() :
    ui(new Ui::LobbyWidget)
{
    ui->setupUi(this);
    connect(ui->exitBtn, SIGNAL(clicked()), this, SIGNAL(c_exit()));
    connect(ui->goBtn, SIGNAL(clicked()), this, SIGNAL(c_go()));

    ui->contentTable->verticalHeader()->setVisible(false);

    //todo load colors codes... this is pretty dirty!
    colors.append("#ffff00");
    colors.append("#00ffff");
    colors.append("#ff0000");
    colors.append("#00ff00");
    colors.append("#0000ff");
    colors.append("#8e0007");
    colors.append("#006700");
    colors.append("#510052");
    colors.append("#e00a6f");
    colors.append("#ffb129");
    colors.append("#bb29ff");
    colors.append("#02b150");
    colors.append("#8e4307");
    colors.append("#000000");
    colors.append("#919191");
    colors.append("#ffffff");

    updateTable();
}

LobbyWidget::~LobbyWidget()
{
    delete ui;
}

void LobbyWidget::addRow(int num)
{
    if (findData(num))
        return;

    rows.append(new RowData{num, "Testplayer", "", "none", "no Status"});
    nextColor(rows.last());
    updateTable();
}

void LobbyWidget::removeRow(int num)
{
    RowData *dataPtr = findData(num);
    if (dataPtr) {
        takenColors.removeAll(dataPtr->color);
        rows.removeAll(dataPtr);
        updateTable();
    }
}

void LobbyWidget::changeColor(int num)
{
    RowData *dataPtr = findData(num);
    if (dataPtr) {
        nextColor(dataPtr);
        updateTable();
    }
}

void LobbyWidget::updateTable()
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
        ui->contentTable->setItem(i, 0, new QTableWidgetItem(rows[i]->playerName));
        ui->contentTable->setItem(i, 1, new QTableWidgetItem(colorItem, ""));
        ui->contentTable->setItem(i, 2, new QTableWidgetItem(rows[i]->controls));
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

void LobbyWidget::nextColor(RowData *data)
{
    int index = colors.indexOf(QRegExp(data->color));
    takenColors.removeAll(data->color);
    data->color = "";
    int cancelCounter = 0;

    while (data->color.isEmpty() && cancelCounter < 16) {
        index++;
        index %= colors.size();

        if (!takenColors.contains(colors[index])) {
            data->color = colors[index];
            takenColors.append(colors[index]);
        }
        cancelCounter++;
    }
}

LobbyWidget::RowData *LobbyWidget::findData(int num)
{
    for (RowData *row: rows) {
        if (row->playerNum == num)
            return row;
    }
    return NULL;
}


