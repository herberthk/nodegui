
#include "qradiobutton_wrap.h"
#include "src/cpp/QtWidgets/QWidget/qwidget_wrap.h"
#include "src/cpp/Extras/Utils/nutils.h"
#include <QWidget>


Napi::FunctionReference QRadioButtonWrap::constructor;

Napi::Object QRadioButtonWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QRadioButton";
  Napi::Function func = DefineClass(env, CLASSNAME, {
    InstanceMethod("setText", &QRadioButtonWrap::setText),
    QWIDGET_WRAPPED_METHODS_EXPORT_DEFINE(QRadioButtonWrap)
  });
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

NRadioButton* QRadioButtonWrap::getInternalInstance() {
  return this->instance.get();
}

QRadioButtonWrap::QRadioButtonWrap(const Napi::CallbackInfo& info): Napi::ObjectWrap<QRadioButtonWrap>(info)  {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if(info.Length() == 1) {
    Napi::Object parentObject = info[0].As<Napi::Object>();
    QWidgetWrap* parentWidgetWrap = Napi::ObjectWrap<QWidgetWrap>::Unwrap(parentObject);
    this->instance = std::make_unique<NRadioButton>(parentWidgetWrap->getInternalInstance()); //this sets the parent to current widget
  }else if (info.Length() == 0){
    this->instance = std::make_unique<NRadioButton>();
  }else {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
  }
  // Adds measure function on yoga node so that widget size is calculated based on its own size.
  YGNodeSetMeasureFunc(this->instance->getFlexNode(), &extrautils::measureQtWidget);
}

QRadioButtonWrap::~QRadioButtonWrap() {
   this->instance.reset();
}

Napi::Value QRadioButtonWrap::setText(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  Napi::String napiText = info[0].As<Napi::String>();
  std::string text = napiText.Utf8Value();
  this->instance->setText(text.c_str()); 
  return env.Null();
}

 