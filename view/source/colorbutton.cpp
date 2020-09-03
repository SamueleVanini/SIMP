#include "view/header/colorbutton.h"

ColorButton::ColorButton(QWidget *parent) : QPushButton(parent)
{}

void ColorButton::setAction(QAction *action)
{

    _action = action;
    updateButtonStatusFromAction();

    connect(action, &QAction::changed,
            this, &ColorButton::updateButtonStatusFromAction);
    connect(this, &ColorButton::clicked,
            _action, &QAction::trigger);
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
    if (!_action)
        return;
    setChecked(_action->isChecked());
}
