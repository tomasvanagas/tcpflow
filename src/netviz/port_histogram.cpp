/**
 * port_histogram.cpp: 
 * Show packets received vs port
 *
 * This source file is public domain, as it is not based on the original tcpflow.
 *
 * Author: Michael Shick <mike@shick.in>
 *
 */

#include "config.h"
#include "tcpflow.h"

#include "port_histogram.h"

const port_histogram::config_t port_histogram::default_config = {
    /* graph */ plot::default_config,
    /* relationship */ port_histogram::SND_OR_RCV,
    /* bar_space_factor */ 1.2,
    /* max_bars */ 10
};

void port_histogram::ingest_packet(const packet_info &pi)
{
}

void port_histogram::render(cairo_t *cr, const plot::bounds_t &bounds)
{
#ifdef CAIRO_PDF_AVAILABLE
    plot::ticks_t ticks;
    plot::legend_t legend;
    plot::bounds_t content_bounds(0.0, 0.0, bounds.width,
            bounds.height);
    //// have the plot class do labeling, axes, legend etc
    plot::render(cr, bounds, ticks, legend, conf.graph, content_bounds);

    //// fill borders rendered by plot class
    //render_bars(cr, content_bounds, vars);
#endif
}
