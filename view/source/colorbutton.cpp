#include "view/header/colorbutton.h"

ColorButton::ColorButton(QWidget *parent) : QPushButton(parent)
{}

void ColorButton::setAction(QAction *action)
{
    // store the action
    actionOwner = action;

    // configure the button
    updateButtonStatusFromAction();

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
    setEnabled(actionOwner->isEnabled());
    setCheckable(actionOwner->isCheckable());
    setChecked(actionOwner->isChecked());
}
