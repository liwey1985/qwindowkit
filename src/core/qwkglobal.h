// Copyright (C) 2023-2024 Stdware Collections (https://www.github.com/stdware)
// Copyright (C) 2021-2023 wangwenx190 (Yuhang Zhao)
// SPDX-License-Identifier: Apache-2.0

#ifndef QWKGLOBAL_H
#define QWKGLOBAL_H

#include <functional>

#include <QtCore/QEvent>
#include <QtGui/QtEvents>

#ifndef QWK_CORE_EXPORT
#  ifdef QWK_CORE_STATIC
#    define QWK_CORE_EXPORT
#  else
#    ifdef QWK_CORE_LIBRARY
#      define QWK_CORE_EXPORT Q_DECL_EXPORT
#    else
#      define QWK_CORE_EXPORT Q_DECL_IMPORT
#    endif
#  endif
#endif

#if (QT_VERSION >= QT_VERSION_CHECK(6, 0, 0))
using QT_NATIVE_EVENT_RESULT_TYPE = qintptr;
using QT_ENTER_EVENT_TYPE = QEnterEvent;
#else
using QT_NATIVE_EVENT_RESULT_TYPE = long;
using QT_ENTER_EVENT_TYPE = QEvent;
#endif

#ifndef QWINDOWKIT_CONFIG
#  define QWINDOWKIT_CONFIG(feature) ((1 / QWINDOWKIT_##feature) == 1)
#endif

#if defined(__GNUC__) || defined(__clang__)
#  define QWINDOWKIT_PRINTF_FORMAT(fmtpos, attrpos)                                                \
      __attribute__((__format__(__printf__, fmtpos, attrpos)))
#else
#  define QWINDOWKIT_PRINTF_FORMAT(fmtpos, attrpos)
#endif

namespace QWK {

    using ScreenRectCallback = std::function<QRect(const QSize &)>;

    using IsWindowFixedSizeCallback = std::function<bool()>;
    using IsInsideTitleBarDraggableAreaCallback = std::function<bool(const QPoint &)>;
    using ShouldIgnoreMouseEventsCallback = std::function<bool(const QPoint &)>;

    // using GetWindowFlagsCallback = std::function<Qt::WindowFlags()>;
    // using SetWindowFlagsCallback = std::function<void(const Qt::WindowFlags)>;
    // using GetWindowSizeCallback = std::function<QSize()>;
    // using SetWindowSizeCallback = std::function<void(const QSize &)>;
    // using GetWindowPositionCallback = std::function<QPoint()>;
    // using SetWindowPositionCallback = std::function<void(const QPoint &)>;
    // using GetWindowScreenCallback = std::function<QScreen *()>;
    // using SetWindowFixedSizeCallback = std::function<void(const bool)>;
    // using GetWindowStateCallback = std::function<Qt::WindowState()>;
    // using SetWindowStateCallback = std::function<void(const Qt::WindowState)>;
    // using GetWindowHandleCallback = std::function<QWindow *()>;
    // using WindowToScreenCallback = std::function<QPoint(const QPoint &)>;
    // using ScreenToWindowCallback = std::function<QPoint(const QPoint &)>;
    // using IsInsideSystemButtonsCallback = std::function<bool(const QPoint &, Global::SystemButtonType *)>;
    // using GetWindowDevicePixelRatioCallback = std::function<qreal()>;
    // using SetSystemButtonStateCallback = std::function<void(const Global::SystemButtonType, const Global::ButtonState)>;
    // using GetWindowIdCallback = std::function<WId()>;
    // using ShowSystemMenuCallback = std::function<void(const QPoint &)>;
    // using SetPropertyCallback = std::function<void(const QByteArray &, const QVariant &)>;
    // using GetPropertyCallback = std::function<QVariant(const QByteArray &, const QVariant &)>;
    // using SetCursorCallback = std::function<void(const QCursor &)>;
    // using UnsetCursorCallback = std::function<void()>;
    // using GetWidgetHandleCallback = std::function<QObject *()>;
    // using ForceChildrenRepaintCallback = std::function<void(const int)>;

}

#endif // QWKGLOBAL_H
