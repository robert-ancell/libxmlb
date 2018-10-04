/*
 * Copyright (C) 2018 Richard Hughes <richard@hughsie.com>
 *
 * SPDX-License-Identifier: LGPL-2.1+
 */

#ifndef __XB_BUILDER_SOURCE_H
#define __XB_BUILDER_SOURCE_H

#include <gio/gio.h>

#include "xb-builder-node.h"

G_BEGIN_DECLS

#define XB_TYPE_BUILDER_SOURCE (xb_builder_source_get_type ())

G_DECLARE_FINAL_TYPE (XbBuilderSource, xb_builder_source, XB, BUILDER_SOURCE, GObject)

/**
 * XbBuilderSourceFlags:
 * @XB_BUILDER_SOURCE_FLAG_NONE:		No extra flags to use
 * @XB_BUILDER_SOURCE_FLAG_LITERAL_TEXT:	Do not attempt to repair XML whitespace
 * @XB_BUILDER_SOURCE_FLAG_WATCH_FILE:		Watch the source file for changes
 *
 * The flags for converting to XML.
 **/
typedef enum {
	XB_BUILDER_SOURCE_FLAG_NONE		= 0,		/* Since: 0.1.0 */
	XB_BUILDER_SOURCE_FLAG_LITERAL_TEXT	= 1 << 0,	/* Since: 0.1.0 */
	XB_BUILDER_SOURCE_FLAG_WATCH_FILE	= 1 << 1,	/* Since: 0.1.0 */
	/*< private >*/
	XB_BUILDER_SOURCE_FLAG_LAST
} XbBuilderSourceFlags;

typedef gboolean (*XbBuilderSourceNodeFunc)	(XbBuilderSource	*self,
						 XbBuilderNode		*bn,
						 gpointer		 user_data,
						 GError			**error);

XbBuilderSource	*xb_builder_source_new_file	(GFile			*file,
						 XbBuilderSourceFlags	 flags,
						 GCancellable		*cancellable,
						 GError			**error);
XbBuilderSource	*xb_builder_source_new_xml	(const gchar		*xml,
						 XbBuilderSourceFlags	 flags,
						 GError			**error);
void		 xb_builder_source_set_info	(XbBuilderSource	*self,
						 XbBuilderNode		*info);
void		 xb_builder_source_set_prefix	(XbBuilderSource	*self,
						 const gchar		*prefix);
void		 xb_builder_source_add_node_func (XbBuilderSource	*self,
						 XbBuilderSourceNodeFunc func,
						 gpointer		 user_data,
						 GDestroyNotify		 user_data_free);

G_END_DECLS

#endif /* __XB_BUILDER_SOURCE_H */
