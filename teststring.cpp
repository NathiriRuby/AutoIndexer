TEST_CASE("Strings are cool", "[string]")
{
    String S("bar");
    SECTION("constructors")
    {
        REQUIRE(strcmp(S.c_str(), "bar")==0);

    }
}
