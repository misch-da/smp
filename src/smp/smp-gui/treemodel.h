#pragma once

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>

#include <global.h>

namespace libsmp {
class ControllerInterface;
class Node;
}

class TreeItem;

inline TreeItem *toTreeItem(void *data) {
    return static_cast<TreeItem *>(data);
}

inline TreeItem *toTreeItem(const QModelIndex &index) {
    return static_cast<TreeItem *>(index.internalPointer());
}

class TreeModel : public QAbstractItemModel {
    Q_OBJECT
public:
    explicit TreeModel(libsmp::sp<libsmp::ControllerInterface> controller, QObject *parent = 0);
    ~TreeModel();

    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    void setItem(const libsmp::Node &item, const QModelIndex &currentIndex);

    TreeItem *getRootItem();

private:
    TreeItem* rootItem = nullptr;
    libsmp::sp<libsmp::ControllerInterface> controller_;
};

