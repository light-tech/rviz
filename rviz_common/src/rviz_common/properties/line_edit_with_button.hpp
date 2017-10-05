/*
 * Copyright (c) 2011, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef RVIZ_LINE_EDIT_WITH_BUTTON_H
#define RVIZ_LINE_EDIT_WITH_BUTTON_H

#include <QLineEdit>

class QPushButton;

namespace rviz_common
{
namespace properties
{

/**
 * A QLineEdit with a square button on the right side that says "...".
 */
class LineEditWithButton: public QLineEdit
{
Q_OBJECT
public:
  LineEditWithButton( QWidget* parent = 0 );

  /** Returns the child button.  Use this to connect() something to a
   * button click. */
  QPushButton* button() { return button_; }

protected:
  virtual void resizeEvent( QResizeEvent* event );

  /** @brief Send key events to mimic the "return" key being pressed and
   * released.  Useful ending an edit session and sending the data on
   * out. */
  void simulateReturnPressed();

protected Q_SLOTS:
  /** @brief Override this to do something when the button is clicked. */
  virtual void onButtonClick() {}

private:
  QPushButton* button_;
};

}  // namespace properties
}  // namespace rviz_common

#endif // RVIZ_LINE_EDIT_WITH_BUTTON_H