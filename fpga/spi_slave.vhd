library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity spi_slave is
generic(
    N : integer := 8
);
port (
    SCK  : in  std_logic;
    CS   : in  std_logic;
    MOSI : in  std_logic;
    LED  : out std_logic_vector(N-1 downto 0)
);
end spi_slave;

architecture rtl of spi_slave is

    -- Shift register containing the received SPI data.
    signal r_rx_data : std_logic_vector(N-1 downto 0);

begin

    -- Drive the FPGA LEDs with the received 8-bit value.
    LED <= r_rx_data(7 downto 0);

    -- SPI slave receive process.
    p_spi_slave_input : process(SCK, CS, MOSI)
    begin
        if rising_edge(SCK) then
            if (CS = '0') then
                r_rx_data <= r_rx_data(N-2 downto 0) & MOSI;
            end if;
        end if;
    end process p_spi_slave_input;

end rtl;
