#include "view/header/colorbutton.h"

ColorButton::ColorButton(QWidget *parent) : QPushButton(parent)
{}

void ColorButton::setAction(QAction *action)
{
    // if I've got already an action associated to the button
    // remove all connections
    if (actionOwner && actionOwner != action) {
        disconnect(actionOwner, &QAction::changed,
                   this, &ColorButton::updateButtonStatusFromAction);
        disconnect(this, &ColorButton::clicked,
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
            this, &ColorButton::updateButtonStatusFromAction);

    // connect the button to the slot that forwards the
    // signal to the action
    connect(this, &ColorButton::clicked,
            actionOwner, &QAction::trigger);
}

void ColorButton::setColor(QColor color)
{
    setText(color.name());
    setStyleSheet(QString("background-color: %1")
                               .arg(color.name()));
    setPalette(QPalette(color));
}

void ColorButton::updateButtonStatusFromAction()
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
