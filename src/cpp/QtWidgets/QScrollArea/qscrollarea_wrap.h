#pragma once

#include <napi.h>
#include <stdlib.h>
#include "nscrollarea.h"
#include "src/cpp/QtWidgets/QAbstractScrollArea/qabstractscrollarea_macro.h"

class QScrollAreaWrap : public  Napi::ObjectWrap<QScrollAreaWrap>{
 private:
  std::unique_ptr<NScrollArea> instance;
 public:
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QScrollAreaWrap(const Napi::CallbackInfo& info);
  ~QScrollAreaWrap();
  NScrollArea* getInternalInstance();
  //class constructor
  static Napi::FunctionReference constructor;
  //wrapped methods
  Napi::Value setWidget(const Napi::CallbackInfo &info);
  Napi::Value takeWidget(const Napi::CallbackInfo &info);

  QABSTRACTSCROLLAREA_WRAPPED_METHODS_DECLARATION 
};

