/* EventListenerProxy.java -- abstract wrapper for event listeners
   Copyright (C) 2002, 2005  Free Software Foundation, Inc.

This file is part of GNU Classpath.

GNU Classpath is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GNU Classpath is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU Classpath; see the file COPYING.  If not, write to the
Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
02110-1301 USA.

Linking this library statically or dynamically with other modules is
making a combined work based on this library.  Thus, the terms and
conditions of the GNU General Public License cover the whole
combination.

As a special exception, the copyright holders of this library give you
permission to link this library with independent modules to produce an
executable, regardless of the license terms of these independent
modules, and to copy and distribute the resulting executable under
terms of your choice, provided that you also meet, for each linked
independent module, the terms and conditions of the license of that
module.  An independent module is a module which is not derived from
or based on this library.  If you modify this library, you may extend
this exception to your version of the library, but you are not
obligated to do so.  If you do not wish to do so, delete this
exception statement from your version. */


package java.util;

/**
 * An abstract wrapper for event listeners.  This allows subclasses to
 * attach additional parameters to an existing event listener to create
 * a new one.  Subclasses are expected to add methods to set and retrieve
 * any attached properties.
 *
 * @author Eric Blake (ebb9@email.byu.edu)
 * @since 1.4
 * @status updated to 1.4
 */
public abstract class EventListenerProxy implements EventListener
{
  /** The listener that this proxy wraps. */
  private final EventListener listener;

  /**
   * Construct a proxy event listener, given an existing one to augment.
   *
   * @param listener the listener to wrap
   */
  public EventListenerProxy(EventListener listener)
  {
    this.listener = listener;
  }

  /**
   * Return the wrapped event listener.
   *
   * @return the listener associated with this proxy
   */
  public EventListener getListener()
  {
    return listener;
  }
} // class EventListenerProxy