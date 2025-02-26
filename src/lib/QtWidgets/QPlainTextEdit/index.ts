import addon from "../../core/addon";
import { NodeWidget } from "../QWidget";
import { BaseWidgetEvents } from "../../core/EventWidget";
import { NativeElement } from "../../core/Component";
import { QAbstractScrollArea } from "../QAbstractScrollArea";
import { QTextOptionWrapMode } from "../../QtGui/QTextOption";

export const QPlainTextEditEvents = Object.freeze({
  ...BaseWidgetEvents,
  textChanged: "textChanged",
  blockCountChanged: "blockCountChanged",
  copyAvailable: "copyAvailable",
  cursorPositionChanged: "cursorPositionChanged",
  modificationChanged: "modificationChanged",
  redoAvailable: "redoAvailable",
  selectionChanged: "selectionChanged",
  undoAvailable: "undoAvailable"
});

export enum LineWrapMode {
  NoWrap,
  WidgetWidth
}
export class QPlainTextEdit extends QAbstractScrollArea {
  native: NativeElement;
  placeholderText?: string;
  constructor(parent?: NodeWidget) {
    let native;
    if (parent) {
      native = new addon.QPlainTextEdit(parent.native);
    } else {
      native = new addon.QPlainTextEdit();
    }
    super(native);
    this.native = native;
    this.parent = parent;
    // bind member functions
    this.setPlainText.bind(this);
    this.setPlaceholderText.bind(this);
    this.toPlainText.bind(this);
    this.setReadOnly.bind(this);
    this.clear.bind(this);
    this.setWordWrapMode.bind(this);
    this.wordWrapMode.bind(this);
    this.setLineWrapMode.bind(this);
    this.lineWrapMode.bind(this);
  }
  setPlainText(text: string | number) {
    // react:✓
    this.native.setPlainText(`${text}`);
  }
  setPlaceholderText(text: string) {
    // react:✓, //TODO:getter
    this.placeholderText = text;
    this.native.setPlaceholderText(text);
  }
  toPlainText(): string {
    // react:✓
    return this.native.toPlainText();
  }
  setReadOnly(isReadOnly: boolean) {
    // react:✓
    this.native.setReadOnly(isReadOnly);
  }
  clear() {
    // react:✓
    this.native.clear();
  }
  setWordWrapMode(mode: QTextOptionWrapMode) {
    this.native.setWordWrapMode(mode);
  }
  wordWrapMode(): QTextOptionWrapMode {
    return this.native.wordWrapMode();
  }
  setLineWrapMode(mode: LineWrapMode) {
    this.native.setLineWrapMode(mode);
  }
  lineWrapMode(): LineWrapMode {
    return this.native.lineWrapMode();
  }
}
