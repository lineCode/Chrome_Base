// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "views/view.h"

// Necessary to define oleacc GUID's.
#include <initguid.h>
#include <oleacc.h>
#include <windows.h>

#include "views/accessibility/native_view_accessibility_win.h"

namespace views {

gfx::NativeViewAccessible View::GetNativeViewAccessible() {
  if (!native_view_accessibility_win_.get())
    native_view_accessibility_win_ = NativeViewAccessibilityWin::Create(this);
  return native_view_accessibility_win_.get();
}

int View::GetHorizontalDragThreshold() {
  static int threshold = -1;
  if (threshold == -1)
    threshold = GetSystemMetrics(SM_CXDRAG) / 2;
  return threshold;
}

int View::GetVerticalDragThreshold() {
  static int threshold = -1;
  if (threshold == -1)
    threshold = GetSystemMetrics(SM_CYDRAG) / 2;
  return threshold;
}

}  // namespace views
