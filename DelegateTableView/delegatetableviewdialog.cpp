#include "delegatetableviewdialog.h"
#include "ui_delegatetableviewdialog.h"

DelegateTableViewDialog
    ::DelegateTableViewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DelegateTableViewDialog)
{
    ui->setupUi(this);

    myDelegate = new MyDelegate(this);

    // Create a new model
    // QStandardItemModel(int rows, int columns, QObject * parent = 0)
    model = new QStandardItemModel(4,2,this);

    // Generate data
    for(int row = 0; row < 4; row++)
    {
        for(int col = 0; col < 2; col++)
        {
            QModelIndex index
                    = model->index(row,col,QModelIndex());
            // 0 for all data
            model->setData(index,0);
        }
    }
    // Attach (tie) the model to the view
    ui->tableView->setModel(model);

    // Tie the View with the new MyDelegate instance
    // If we don not set this, it will use default delegate
    ui->tableView->setItemDelegate(myDelegate);
}

DelegateTableViewDialog::~DelegateTableViewDialog()
{
    delete ui;
}
