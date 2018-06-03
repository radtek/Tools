﻿using System.ComponentModel.Design;
using System.Windows.Forms.Design;

namespace DesignUI.Service.OptionService
{
    internal class DesignerOptionServiceGridWithoutSnapping : DesignerOptionService
    {
        private System.Drawing.Size _gridSize;

        public DesignerOptionServiceGridWithoutSnapping(System.Drawing.Size gridSize) : base() { _gridSize = gridSize; }

        protected override void PopulateOptionCollection(DesignerOptionCollection options)
        {
            if (null != options.Parent) return;

            DesignerOptions ops = new DesignerOptions();
            ops.GridSize = _gridSize;
            ops.SnapToGrid = false;
            ops.ShowGrid = true;
            ops.UseSnapLines = false;
            ops.UseSmartTags = true;
            DesignerOptionCollection wfd = this.CreateOptionCollection(options, "WindowsFormsDesigner", null);
            this.CreateOptionCollection(wfd, "General", ops);
        }
    }
}
