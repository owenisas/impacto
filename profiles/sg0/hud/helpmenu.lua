root.SpriteSheets["HelpPage0"] = { Path = { Mount = "manual", Id = 0 }, DesignWidth = 1920, DesignHeight = 1080 };
root.SpriteSheets["HelpPage1"] = { Path = { Mount = "manual", Id = 1 }, DesignWidth = 1920, DesignHeight = 1080 };
root.Sprites["HelpPage0"] = { Sheet = "HelpPage0", Bounds = { X = 0, Y = 0, Width = 1920, Height = 1080 } };
root.Sprites["HelpPage1"] = { Sheet = "HelpPage1", Bounds = { X = 0, Y = 0, Width = 1920, Height = 1080 } };

root.HelpMenu = {
    Type = HelpMenuType.SG0,
    DrawType = DrawComponentType.SystemMenu,
    PageSprites = { "HelpPage0", "HelpPage1" },
    CountMax = 32
};
