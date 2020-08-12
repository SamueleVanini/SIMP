#include "view/header/colorbutton.h"

colorButton::colorButton(QWidget *parent) :
    QPushButton(parent)
{}

void colorButton::setAction(QAction *action)
{
    // if I've got already an action associated to the button
    // remove all connections
    if (actionOwner && actionOwner != action) {
        disconnect(actionOwner, &QAction::changed,
                   this, &colorButton::updateButtonStatusFromAction);
        disconnect(this, &colorButton::clicked,
                   actionOwner, &QAction::trigger);
    }

    // store the action
    actionOwner = action;

    // configure the button
    updateButtonStatusFromAction();

    // connect the action and the button
    // so that when the action is changed the
    // button is changed too!
    connect(action, &QAction::changed,
            this, &colorButton::updateButtonStatusFromAction);

    // connect the button to the slot that forwards the
    // signal to the action
    connect(this, &colorButton::clicked,
            actionOwner, &QAction::trigger);
}

void colorButton::setColor(QColor color)
{
    setText(color.name());
    setStyleSheet(QString("background-color: %1")
                               .arg(color.name()));
    setPalette(QPalette(color));
}

void colorButton::updateButtonStatusFromAction()
{
    if (!actionOwner)
        return;
    setText(actionOwner->text());
    setStatusTip(actionOwner->statusTip());
    setToolTip(actionOwner->toolTip());
    setIcon(actionOwner->icon());
    setEnabled(actionOwner->isEnabled());
    setCheckable(actionOwner->isCheckable());
    setChecked(actionOwner->isChecked());
}
