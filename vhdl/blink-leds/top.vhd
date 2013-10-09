-- Blink LEDs
-- Jenner Hanni
-- First program for the Terasic DE0-Nano
-----------------------------------------

library ieee;
use ieee.numeric_std.all

-----------------------------------------

entity blink_led is
  port (
    clk : in  std_logic;
    btn : in  std_logic_vector(1 downto 0);
    led : out std_logic_vector(7 downto 0);
  );
end blink_led;

-----------------------------------------

architecture behavioral of blink_led is 

  -- signals, constants, etc. other declarations

begin

  -- concurrent signal assignments
  -- process statements
  -- conditional signal assignments
  -- selected signal assignment
  -- component instantiation statement
  -- generate statement

end behavioral;

