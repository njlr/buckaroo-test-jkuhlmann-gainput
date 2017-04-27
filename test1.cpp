#include <gtest/gtest.h>
#include <gainput/gainput.h>

TEST(gainput, keyboard) {

  using namespace gainput;

  InputManager manager;
  InputDeviceKeyboard* device = manager.CreateAndGetDevice<InputDeviceKeyboard>();

  ASSERT_TRUE(device);
  ASSERT_TRUE(device->GetIndex() == 0);
  ASSERT_TRUE(device->GetDeviceId() != InvalidDeviceId);
  ASSERT_TRUE(device->GetType() == InputDevice::DT_KEYBOARD);
  ASSERT_TRUE(device->GetTypeName());
  ASSERT_TRUE(device->IsValidButtonId(KeyEscape));
  ASSERT_TRUE(device->IsValidButtonId(KeyReturn));
  ASSERT_TRUE(device->IsValidButtonId(Key1));
  ASSERT_TRUE(device->IsValidButtonId(KeyA));
  ASSERT_TRUE(device->IsValidButtonId(KeyZ));
  ASSERT_TRUE(device->IsValidButtonId(KeySpace));
  char buf[32];
  ASSERT_TRUE(device->GetButtonName(KeyF10, buf, 32) > 0);
  ASSERT_TRUE(device->GetButtonName(KeyRightParenthesis, buf, 32) > 0);
  ASSERT_TRUE(device->GetButtonName(KeyPeriod, buf, 32) > 0);
  ASSERT_TRUE(device->GetButtonName(KeyV, buf, 32) > 0);
  ASSERT_TRUE(device->GetButtonName(KeySpace, buf, 32) > 0);
  ASSERT_TRUE(device->GetButtonType(KeyEscape) == BT_BOOL);
  ASSERT_TRUE(device->GetButtonType(Key2) == BT_BOOL);
  ASSERT_TRUE(device->GetButtonType(KeyD) == BT_BOOL);
  ASSERT_TRUE(device->GetButtonType(KeyBackSpace) == BT_BOOL);
  ASSERT_TRUE(device->GetButtonByName("space") == KeySpace);
  ASSERT_TRUE(device->GetButtonByName("5") == Key5);
  ASSERT_TRUE(device->GetInputState());
  ASSERT_TRUE(device->GetPreviousInputState());
  ASSERT_TRUE(device->IsTextInputEnabled());
  device->SetTextInputEnabled(false);
  ASSERT_TRUE(!device->IsTextInputEnabled());
}
